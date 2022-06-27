class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        //dfs and delete island
        int n = grid1.size();
        int m = grid1[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    if(grid1[i][j]==1){
                        cnt+=dfs(i,j,grid1,grid2);
                    }
                    else deleteisland(i,j,grid1,grid2);
                }
            }
        }
        return cnt;
    }
    
    void deleteisland(int i,int j , vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(i<0 || j<0 || i>=grid1.size() || j>=grid1[0].size()) return;
        
        grid2[i][j]=0;

        dfs(i-1,j,grid1,grid2);
        dfs(i,j+1,grid1,grid2);
        dfs(i,j-1,grid1,grid2);
        dfs(i+1,j,grid1,grid2);
    }
    
    bool dfs(int i,int j , vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(i<0 || j<0 || i>=grid1.size() || j>=grid1[0].size()) return true;
        if(grid2[i][j]==0) return true;
        
        if(grid2[i][j]==1 && grid1[i][j]==0){ 
            deleteisland(i,j,grid1,grid2);
            return false;
        }
        grid2[i][j]=0;
        
        return (dfs(i+1,j,grid1,grid2)
               &dfs(i-1,j,grid1,grid2)
               &dfs(i,j+1,grid1,grid2)
               &dfs(i,j-1,grid1,grid2));
        
    }
        
};