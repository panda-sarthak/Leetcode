class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(n,INT_MIN);
        dp[n-1]=0;
        for(int idx=n-2;idx>=0;idx--){
            int res=INT_MIN;
            for (int j=idx+1;j<n;j++) {
                if (abs((long long)nums[j]-nums[idx])>target) continue;
                int x=dp[j];
                if(x==INT_MIN) continue;
                res=max(res,1+x);
            }
            dp[idx]=res;
        }
        int r=dp[0];
        return (r==INT_MIN)?-1:r;
    }
};