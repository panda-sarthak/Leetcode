class Solution {
public:
    int t[1001];
    void buildAdj(vector<vector<int>>&adj,const vector<int>& nums,const int& target){
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if (abs((long long)nums[j] - nums[i]) <= target) {
                    adj[i].push_back(j);
                }
            }
        }
    }
    int solve(int idx,const int&n,const vector<vector<int>>&adj){
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
        vector<vector<int>>adj(n);
        buildAdj(adj,nums,target);
        int r=solve(0,n,adj);
        return (r==INT_MIN)?-1:r;
    }
};