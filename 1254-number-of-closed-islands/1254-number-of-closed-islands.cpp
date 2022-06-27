class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        // traverse from edges and do dfs whenever u find 
        // a 0 on edge make it 1 
        // after that we are left with only islands inside the grid
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 || j==0 || i==(grid.size()-1) || j==(grid[0].size()-1) ){
                    if(grid[i][j]==0) 
                        dfs(grid,i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    dfs(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    void dfs(vector<vector<int>>&grid,int i ,int j){
        if(i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1 || grid[i][j]==1) return ;
        
        grid[i][j]=1;
        
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);

    }
};