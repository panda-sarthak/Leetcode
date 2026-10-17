class Solution {
public:
    int t[1001];
    void buildAdj(vector<unordered_set<int>>&adj,const vector<int>& nums,const int& target){
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++) v.push_back({nums[i],i});
        sort(v.begin(),v.end(),[](const auto&a,const auto&b){
            return (a.first<b.first)||((a.first==b.first)&&(a.second<b.second));
        });
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                if(abs(v[j].first-v[i].first)>target) continue;
                if(v[j].second<=v[i].second) continue;
                adj[v[i].second].insert(v[j].second);
            }
        }
    }
    int solve(int idx,const int&n,const vector<unordered_set<int>>&adj){
        if(idx==n-1) return 0;
        int res=INT_MIN;
        if(t[idx]!=-1) return t[idx];
        for(auto&v:adj[idx]){
            int x=solve(v,n,adj);
            if(x==INT_MIN) continue;
            res=max(res,1+x);
        }
        return t[idx]=res;
    }
    int maximumJumps(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
        int n=nums.size();
        vector<unordered_set<int>>adj(n);
        buildAdj(adj,nums,target);
        int r=solve(0,n,adj);
        return (r==INT_MIN)?-1:r;
    }
};