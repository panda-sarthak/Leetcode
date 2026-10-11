class Solution {
public:
    int diff_freq[100001];
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        memset(diff_freq,0,sizeof(diff_freq)); int n=nums1.size(),max_diff=0,curr_diff,k=k1+k2;
        for(int i=0;i<n;i++) curr_diff=abs(nums2[i]-nums1[i]),max_diff=max(max_diff,curr_diff),diff_freq[curr_diff]++;
        for(int diff=max_diff;diff>0 && k>0;diff--){
            int curr_ops=min(diff_freq[diff],k);
            diff_freq[diff]-=curr_ops;
            diff_freq[diff-1]+=curr_ops;
            k-=curr_ops;
        }
        int idx=0;
        return accumulate(diff_freq,diff_freq+max_diff+1,0LL,[&](long long acc,int x){
            acc+=1LL*x*idx*idx; idx++; return acc;
        });
    }
};