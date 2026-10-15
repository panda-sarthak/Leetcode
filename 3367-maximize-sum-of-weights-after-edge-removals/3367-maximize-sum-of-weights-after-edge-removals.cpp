typedef long long ll;
class Solution {
public:
    ll t[100007][2];
    ll solve(int i,bool is_par_edge_removed,int par,const int&k,const vector<vector<pair<int,int>>>&adj){
        if(t[i][is_par_edge_removed]!=-1) return t[i][is_par_edge_removed];
        int num_of_edges_or_childs_to_be_removed=max(static_cast<int>(adj[i].size()-k-is_par_edge_removed),0);
        vector<pair<ll,ll>>candidates; ll result=0;
        for(auto&[j,w]:adj[i]){
            if(j==par) continue;
            ll not_removed=w+solve(j,false,i,k,adj);
            ll removed=solve(j,true,i,k,adj);
            candidates.push_back({not_removed,removed});
        }
        sort(candidates.begin(),candidates.end(),[](const auto&a,const auto&b){
            return (a.first-a.second)<(b.first-b.second);//lower nr-r at first, best to be removed are at beginning 
        });
        int idx=0;
        for(auto&[nr,r]:candidates){
            if(idx<num_of_edges_or_childs_to_be_removed) result+=r;//no choice needs to be removed
            else result+=max(nr,r);
            idx++;
        }
        return t[i][is_par_edge_removed]=result;
    }
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n=edges.size()+1;
        vector<vector<pair<int,int>>>adj(n);
        memset(t,-1,sizeof(t));
        for(auto&e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        return solve(0,false,-1,k,adj);
    }
};