typedef long long ll;
class Solution {
public:
    ll dp[5];
    long long maxScore(vector<int>& a, vector<int>& b) {
        for(int i=0;i<5;i++) dp[i]=LLONG_MIN; dp[0]=0;
        for(auto&x:b){
            for(int k=4;k>0;k--){
                if(dp[k-1]!=LLONG_MIN) dp[k]=max(dp[k],dp[k-1]+1LL*a[k-1]*x);
            }
        }
        return dp[4];
    }
};