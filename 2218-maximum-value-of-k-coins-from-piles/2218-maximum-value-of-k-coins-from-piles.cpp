class Solution {
public:
    int t[1001][2004];
    int solve(int idx,int k,const int&n,const vector<vector<int>>&prefix_sum){
        if(k==0) return 0;
        if(idx>=n) return INT_MIN;//k!=0, we need to use exactly k coins
        if(t[idx][k]!=-1) return t[idx][k];
        int res=0; int l=prefix_sum[idx].size();
        for(int i=0;i<l;i++){
            if(k>=i){
                res=max(res,prefix_sum[idx][i]+solve(idx+1,k-i,n,prefix_sum));
            }
        }
        return t[idx][k]=res;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>>prefix_sum(n);
        for(int i=0;i<n;i++){
            prefix_sum[i].push_back(0);
            for(int j=0;j<piles[i].size();j++){
                prefix_sum[i].push_back(prefix_sum[i][j]+piles[i][j]);
            }
        }
        memset(t,-1,sizeof(t));
        return solve(0,k,n,prefix_sum);
    }
};