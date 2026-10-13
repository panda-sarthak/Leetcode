class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long res=0;
        for(auto&num:nums) num=abs(num);
        sort(nums.begin(),nums.end());
        int n=nums.size(),lh=n/2,i=0;
        while(i<lh) res-=(1LL*nums[i]*nums[i]),i++;
        while(i<n) res+=(1LL*nums[i]*nums[i]),i++;
        return res;
    }
};