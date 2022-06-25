class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // dfs 
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    void dfs(int i,int j ,vector<vector<char>>&grid){
         if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!='1' || grid[i][j]=='0') return ; 
        grid[i][j] = '0';
        
        // if((i+1)<grid.size() && grid[i+1][j]=='1') 
            dfs(i+1,j,grid);
        
        // if((j+1)<grid[0].size() && grid[i][j+1]=='1') 
            dfs(i,j+1,grid);
            
        // if((i-1)>=0 && grid[i-1][j]=='1') 
            dfs(i-1,j,grid);
        
        // if((j-1)>=0 && grid[i][j-1]=='1') 
            dfs(i,j-1,grid);
        
        return ;
        
    }
};
























