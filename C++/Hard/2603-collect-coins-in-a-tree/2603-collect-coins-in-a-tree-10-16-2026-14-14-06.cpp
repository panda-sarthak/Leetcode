class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n=coins.size();
        vector<unordered_set<int>>adj(n);
        for(auto&e:edges){
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        queue<int>coin_less_leafs;
        for(int node=0;node<n;node++){
            if(adj[node].size()==1 && (coins[node]==0)) coin_less_leafs.push(node);
        }
        while(!coin_less_leafs.empty()){
            int curr=coin_less_leafs.front();
            coin_less_leafs.pop();
            for(auto&j:adj[curr]){
                adj[j].erase(curr);
                if(adj[j].size()==1 && (coins[j]==0)) coin_less_leafs.push(j);
            }
            adj[curr].clear();
        }
        //now all leaves have coins, now two rounds of pruning needed to get to core/mmust visit guys
        for(int round=0;round<2;round++){
            vector<int>curr_leafs;
            for(int node=0;node<n;node++){
                if(adj[node].size()==1) curr_leafs.push_back(node);
            }
            for(auto&leaf:curr_leafs){
                for(auto&neigh:adj[leaf]){
                    adj[neigh].erase(leaf);
                }
                adj[leaf].clear();
            }
        }
        //now just calculate total number of edges that are present in core
        //answer is just twice of it;
        int res=0;
        for(auto&e:edges){
            if(adj[e[0]].count(e[1]) && adj[e[1]].count(e[0])) res++;
        }
        return 2*res;
    }
};