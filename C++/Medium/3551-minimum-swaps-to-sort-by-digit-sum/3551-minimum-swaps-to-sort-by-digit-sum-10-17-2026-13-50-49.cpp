inline int getDigSum(int x){
    int res=0;
    while(x>0) res+=x%10,x=x/10;
    return res;
}
struct DSU{
    int n;
    unordered_map<int,int>par,rank;
    DSU(int n):n(n){
        par.reserve(2*n);
        rank.reserve(2*n);
    }
    void _intiate_(int x){
        if(!par.count(x)){
            par[x]=x;
            rank[x]=1;
        }
    }
    int find(int x){
        _intiate_(x);
        if(x!=par[x]) par[x]=find(par[x]);
        return par[x];
    }
    bool unite(int x,int y){
        _intiate_(x);_intiate_(y);
        x=find(x);y=find(y);
        if(x==y) return false;
        if(rank[x]<rank[y]) swap(x,y);
        par[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
        return true;
    }
};
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int>nums_copy=nums;
        sort(nums.begin(),nums.end(),[](const auto&a,const auto&b){
            int da=getDigSum(a);
            int db=getDigSum(b);
            return (da<db)||(da==db && a<b);
        });
        int n=nums.size();
        DSU d(n);
        for(int i=0;i<n;i++){
            if(nums_copy[i]!=nums[i]){
                d.unite(nums_copy[i], nums[i]);
            }
        }
        int res=0;
        for(auto&[k,v]:d.par){
            if(k!=v) res++;
        }
        return res;
    }
};