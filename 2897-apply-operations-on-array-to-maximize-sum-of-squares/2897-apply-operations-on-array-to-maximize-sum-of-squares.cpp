#define fr(i,n) for(int i=0;i<n;i++)
class Solution {
public:
    int freq[32]; long long MOD=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        memset(freq,0,sizeof(freq));
        for(auto&num:nums){
            for(int i=0;i<32;i++){
                if((num>>i)&1) freq[i]++;
            }
        }
        long long res=0;
        while(k--){
            int curr=0;
            for(int i=0;i<32;i++){
                if(freq[i]) freq[i]--,curr|=(1<<i);
            }
            res=(res+(1LL*curr*curr))%MOD;
        }
        return res;
    }
};