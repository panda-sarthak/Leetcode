class Solution {
public:
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    bool dfs(int i, int j, vector<vector<bool>>&visited, const int&n, const int&m, const vector<vector<int>>& grid2, const vector<vector<int>>& grid1){
        visited[i][j]=true;
        bool res=(grid1[i][j]==0);
        for(auto&[di,dj]:dir){
            int ni=i+di,nj=j+dj;
            if(ni<0||ni>=n||nj<0||nj>=m||visited[ni][nj]||grid2[ni][nj]==0) continue;
            res|=dfs(ni,nj,visited,n,m,grid2,grid1);
        }
        return res;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int res=0,n=grid1.size(),m=grid1[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(!visited[i][j] && grid2[i][j]==1 && grid1[i][j]==1 && !dfs(i,j,visited,n,m,grid2,grid1)) res++;
        }
        return res;
    }
};