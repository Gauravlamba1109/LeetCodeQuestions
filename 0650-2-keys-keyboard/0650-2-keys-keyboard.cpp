class Solution {
public:
    int nn;
    int limit;
    int minSteps(int n) {
        nn = n ;
        limit = n;
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        return dfs(1,0,0,dp);
    }

    int dfs(int s, int c, int t, vector<vector<int>>&dp){
        if(s==nn) return t;
        if(s>nn || t>limit) return INT_MAX;

        if(dp[s][c]!=INT_MAX) return dp[s][c];
        // cpy
        int cpy = (s!=c) ? dfs(s,s, t+1,dp) : INT_MAX;
        // pst
        int pst = dfs(s+c,c, t+1,dp);

        int ans = INT_MAX ;
        ans=min({ans,pst,cpy});
        dp[s][c]=min(dp[s][c],ans);
        return ans;
    }
};