class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i = 0;i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ans = max(ans,dfs(i,j,grid,grid.size(),grid[0].size()));
                }
            }
        }
        return ans;
    }
    vector<vector<int>>dir = {{-1,0},{0,-1},{1,0},{0,1}};
    
    int dfs(int i,int j,vector<vector<int>>&grid, int n,int m){
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]==0) return 0;
        
        grid[i][j]=0;
        
        int ans = 1;
        
        for(vector<int> pos: dir)
            ans+= dfs(i+pos[0],j+pos[1],grid,n,m);
            
        return ans;
    }
};