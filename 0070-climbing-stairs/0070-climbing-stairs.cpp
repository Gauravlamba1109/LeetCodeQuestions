class Solution {
public:
    
    int climbStairs(int n,vector<int>&dp){
        if(n<=0) return 0;
        if(n==1 || n==2) return n;
        
        if(dp[n]!=-1) return dp[n]; 
        
        dp[n]=((n-2>0)?climbStairs(n-2,dp):0)+((n-1>0)?climbStairs(n-1,dp):0);
        return dp[n];

    }
    int climbStairs(int n) {
        vector<int>dp(46,-1);
        return climbStairs(n,dp);
    }
};