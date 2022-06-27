class Solution {
public:
int numEnclaves(vector<vector<int>>& grid) {
int n=grid.size();
int m=grid[0].size();
for(int i=0;i<n;i++){
if(grid[i][0]==1) dtz(i,0,grid);
if(grid[i][m-1]==1) dtz(i,m-1,grid);
}
for(int j=0;j<m;j++){
if(grid[0][j]==1) dtz(0,j,grid);
if(grid[n-1][j]==1) dtz(n-1,j,grid);
}
int size=0;
for(int i=1;i<n-1;i++){
for(int j=1;j<m-1;j++){
if(grid[i][j]==1){
int s=0;
size=max(siz(i,j,grid,0),size);
}
}
}
return size;
}
int si=0;
int siz(int i,int j,vector<vector<int>>&grid,int s){
if(grid[i][j]==1)si++;
grid[i][j]=2;
for(int d=1;d<5;d++){
int x=i+dir[d-1],y=j+dir[d];
if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size()){
if(grid[x][y]==1)siz(x,y,grid,s);
}
}
return si;
}
int dir[5]={-1,0,1,0,-1};
void dtz(int i,int j,vector<vector<int>>&grid){
grid[i][j]=0;
for(int d=1;d<5;d++){
int x=i+dir[d-1],y=j+dir[d];
if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size()){
if(grid[x][y]==1)dtz(x,y,grid);
}
}
}
};