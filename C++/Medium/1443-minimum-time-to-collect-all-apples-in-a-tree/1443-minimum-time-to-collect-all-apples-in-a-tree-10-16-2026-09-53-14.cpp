class Solution {
public:
    int solve(int i,int par,const vector<bool>& hasApple,const vector<vector<int>>&adj){
        int res=0;
        for(auto&j:adj[i]){
            if(j==par) continue;
            int time_from_child=solve(j,i,hasApple,adj);
            if(time_from_child>0||hasApple[j]){
                res+=(time_from_child+2);
            }
        }
        return res;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        for(auto&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return solve(0,-1,hasApple,adj);
    }
};