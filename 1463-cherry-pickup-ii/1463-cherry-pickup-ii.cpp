class Solution {
public:
    int t[71][71][71];
    int solve(int r, int c1, int c2,const int&n,const int &m, const vector<vector<int>>& grid){
        if(c1<0||c1>=m||c2<0||c2>=m||r>=n)return INT_MIN;
        int curr=((grid[r][c1])+(grid[r][c2])-(c1==c2)*(grid[r][c1])); 
        if(r==n-1) return curr;
        if(t[r][c1][c2]!=-1) return t[r][c1][c2];
        int mx=INT_MIN;
        for(int i=-1;i<=1;i++)for(int j=-1;j<=1;j++) mx=max(mx,solve(r+1,c1+i,c2+j,n,m,grid));
        return t[r][c1][c2]=(mx==INT_MIN)?INT_MIN:(mx+curr);
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,m-1,n,m,grid);
    }
};