class Solution {
public:
    vector<vector<int>>dir= {{1,0},{-1,0},{0,1},{0,-1}};
    const static int mod = 1000000007;
    bool isvalid(int i,int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m) return false; // out of bounds
        return true; // in bounds 
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>grid(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        int ans=0;
        for(int i=1;i<=maxMove;i++) ans=(ans+dfs(startRow,startColumn,m,n,i,grid))%mod;
        
        return ans%mod;
    }
    
    int dfs(int i, int j, int n ,int m, int moves,vector<vector<vector<int>>>&grid){
        if(isvalid(i,j,n,m)){
            if(grid[i][j][moves]>=0) return grid[i][j][moves];
            if(moves==0) 
                return 0;
            int ans=0;
            // can move to 4 direction 
            for(auto d : dir) ans=(ans+dfs(i+d[0],j+d[1],n,m,moves-1,grid))%mod;
            return grid[i][j][moves]=ans;
        }
        return moves==0;        
    }
};