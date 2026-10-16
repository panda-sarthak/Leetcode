typedef long long ll;
class Solution {
public:
    ll t[100002][2];
    ll solve(int i,bool par_edge_selected,int par,const vector<vector<pair<int,int>>>&adj){
        if(t[i][par_edge_selected]!=-1) return t[i][par_edge_selected];
        ll res=0;
        ll best_cand_comp=0;
        for(auto&[j,w]:adj[i]){
            if(j!=par){
                if(par_edge_selected){
                    ll r=solve(j,false,i,adj);
                    res+=max(r,0LL);//we can skip it entirely if no pos contribution
                }
                else{
                    ll r1=solve(j,false,i,adj);
                    ll r2=solve(j,true,i,adj)+w;
                    ll curr_gain=r2-max(r1,0LL);
                    if(best_cand_comp<curr_gain && curr_gain>0){
                        best_cand_comp=curr_gain;
                    }
                    res+=max(r1,0LL);
                }
            }
        }
        if(par_edge_selected) return t[i][par_edge_selected]=res;
        else return t[i][par_edge_selected]=(best_cand_comp+res);
    }
    long long maxScore(vector<vector<int>>& edges) {
        int n=edges.size();
        memset(t,-1,sizeof(t));
        vector<vector<pair<int,int>>>adj(n);
        for(int i=1;i<edges.size();i++){
            adj[i].push_back({edges[i][0],edges[i][1]});
            adj[edges[i][0]].push_back({i,edges[i][1]});
        }
        return solve(0,false,-1,adj);
    }
};