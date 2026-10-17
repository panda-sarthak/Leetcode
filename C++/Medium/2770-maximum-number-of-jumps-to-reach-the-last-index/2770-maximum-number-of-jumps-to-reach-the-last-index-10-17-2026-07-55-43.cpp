class Solution {
public:
    int t[1001];
    int solve(int idx,const int&n,const vector<int>& nums, const int& target){
        if(idx==n-1) return 0;
        if(t[idx]!=-1) return t[idx];
        int res=INT_MIN;
        for (int j = idx + 1; j < n; j++) {
            if (abs((long long)nums[j] - nums[idx]) > target)
                continue;
            int x=solve(j,n,nums,target);
            if(x==INT_MIN) continue;
            res=max(res,1+x);
        }
        return t[idx]=res;
    }
    int maximumJumps(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
        int n=nums.size();
        int r=solve(0,n,nums,target);
        return (r==INT_MIN)?-1:r;
    }
};