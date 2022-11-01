class Solution {
public:
vector<int> findBall(vector<vector<int>>& grid) {
if(grid[0].size()==1) return {-1};
vector<int>ans(grid[0].size(),-1);
for(int i=0;i<grid.size();i++){
for(int j=0;j<grid[0].size();j++){
if(grid[i][j]==1 && (j+1<grid[0].size()) && grid[i][j+1]==-1){
grid[i][j]=0;
grid[i][j+1]=0;
}
}
}
for(int i=0;i<grid[0].size();i++){
int t = dfs(grid,0,i);
ans[i] = (t<grid[0].size() && t>-1)?t:-1;
}
return ans ;
}
int dfs(vector<vector<int>>&grid,int i,int j){
if(j>=(grid[0].size()) || j<0 || grid[i][j]==0) return -1;
if(i==(grid.size()-1)) return j+grid[i][j];
return dfs(grid,i+1,j+grid[i][j]);
}
};