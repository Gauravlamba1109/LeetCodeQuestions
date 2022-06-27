class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        // traverse from edges and do dfs whenever u find 
        // a 0 on edge make it 1 
        // after that we are left with only islands inside the grid
        
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0) 
                    cnt+=dfs(grid,i,j);
            }
        }
        return cnt;
    }
    
    bool dfs(vector<vector<int>>&grid,int i ,int j){
        if(i==0 || j==0 || i==(grid.size()-1) || j==(grid[0].size()-1) ) return 0;
        
        grid[i][j]=1;
        bool ans=1;
        if((i+1)<grid.size() && grid[i+1][j]==0) ans&=dfs(grid,i+1,j);
        if((j+1)<grid[0].size() && grid[i][j+1]==0) ans&=dfs(grid,i,j+1);
        if((i-1)>=0 && grid[i-1][j]==0) ans&=dfs(grid,i-1,j);
        if((j-1)>=0 && grid[i][j-1]==0) ans&=dfs(grid,i,j-1);
        
        return ans;
    }
};