class Solution {
public:
    int t[51][51][51];
    //think of two persons starting from 0,0 to corner simultaneously
    int help(int r1,int c1,int r2,const int&n,const int&m,const vector<vector<int>>& grid){
        int c2=(r1+c1)-r2;//reduced state to three params, so recompting back, advantage of 3 simultaneous
        if(r1==n-1 && c1==m-1 && r2==n-1) return (grid[r1][c1]==1);
        if(r1>=n||r2>=n||c1>=m||c2>=m||grid[r1][c1]==-1||grid[r2][c2]==-1) return INT_MIN;//INT_MIN will denote unreachability
        if(t[r1][c1][r2]!=-1) return t[r1][c1][r2];
        int res1=help(r1+1,c1,r2,n,m,grid);//DR
        int res2=help(r1,c1+1,r2,n,m,grid);//RR
        int res3=help(r1+1,c1,r2+1,n,m,grid);//DD
        int res4=help(r1,c1+1,r2+1,n,m,grid);//RD
        int mx=max({res1,res2,res3,res4});
        if(mx==INT_MIN) return t[r1][c1][r2]=INT_MIN;
        int curr=((grid[r1][c1]==1)+(grid[r2][c2]==1)-(r1==r2 && c1==c2 && grid[r1][c1]==1));
        return t[r1][c1][r2]=(curr+mx);
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        memset(t,-1,sizeof(t));
        int z=help(0,0,0,n,m,grid);
        return (z==INT_MIN)?0:z;
    }
};