typedef long long ll;
class Solution {
public:
    ll solve(int idx,int k,const vector<int>& a,const int&n,const vector<int>& b,vector<vector<ll>>&t){
        if(k==0) return 0LL;
        if(idx>=n) return LLONG_MIN;
        if(t[idx][k]!=LLONG_MIN) return t[idx][k];
        ll r1=solve(idx+1,k-1,a,n,b,t);
        ll r2=solve(idx+1,k,a,n,b,t);
        if(r1!=LLONG_MIN) r1+=(1LL*a[4-k]*b[idx]);
        return t[idx][k]=max(r1,r2);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<ll>>t(b.size()+2,vector<ll>(a.size()+2,LLONG_MIN));
        return solve(0,4,a,b.size(),b,t);
    }
};