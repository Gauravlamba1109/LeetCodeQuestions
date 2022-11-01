class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans(grid[0].size(),0);
        // doin a dfs form each jth pos 
        // if its not valid it will put -1 in ans;
        
        for(int i=0;i<grid[0].size();i++){
            ans[i]=dfs(grid,0,i);
            if(ans[i]==-2)ans[i]=-1;
        }
        
        return ans;
    }
    
    
    int dfs(vector<vector<int>>&grid,int i,int j){
        
        // if reached end then put j ;
        if(i==grid.size()) return j;
        
        if(grid[i][j]==1){
            // if not valid pos 
            if(j==(grid[0].size()-1) || grid[i][j+1]==-1) return -2;
            return dfs(grid,i+1,j+1);
            
        }else if(grid[i][j]==-1){
            // if not valid 
            if(j==0 || grid[i][j-1]==1) return -2;
            return dfs(grid,i+1,j-1);
        }
        
        return -1;
    }
};