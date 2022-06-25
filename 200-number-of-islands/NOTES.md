int g(int i,int j){
return i*n+j;
}
int find(int p){
while(p != parent[p]) {
parent[p] = parent[parent[p]];
p = parent[p];
}
return p;
​
}
void uni(int x,int y){
int ix=find(x);
int iy=find(y);
if(ix==iy) return ;
parent[ix]=iy;
count++;
}
};
​
​
​
//////////////////////////
class Solution {
public:
int dirs[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int numIslands(vector<vector<char>>& grid) {
int count=0;
for(int i=0;i<grid.size();i++){
for(int j=0;j<grid[0].size();j++){
if(grid[i][j]=='1'){
count++;
dfs(grid,i,j);
}
}
}