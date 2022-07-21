class Solution {
public:
    int solve(int start,vector<int>& slices, int end,int n, vector<vector<int>>&dp){
        if(start>end || n==0) return 0;
        if(dp[start][n]!=-1) return dp[start][n];
        
        int inc = slices[start]+ solve(start+2,slices,end,n-1,dp);
        int noc = 0 + solve(start+1,slices,end,n,dp);
        
        return dp[start][n]=max(inc,noc);
    }
    
    
    int maxSizeSlices(vector<int>& slices) {
        // if you eat 1st u cnt take 2nd and last 
        // if you eat last u cnt take 1st and last-1 
        // i can take k/3 slices only as 2 friends are also pr 
        
        
        int k = slices.size();
        vector<vector<int>>dp(k+1,vector<int>(k/3+1,-1));
                        //    start,     ,end ,slice
        int firststart = solve(0,slices,k-2,k/3,dp);
        
        vector<vector<int>>dp2(k+1,vector<int>(k/3+1,-1));
        int secondstart= solve(1,slices,k-1,k/3,dp2);
        
        
        return max(firststart,secondstart);
    }
};