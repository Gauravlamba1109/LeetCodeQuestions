class Solution {
public:
    int numWays(int steps, int arrLen) {
        vector<vector<int>>dp(1000,vector<int>(steps+1,-1));
        return dfs(0,steps,arrLen,dp);
    }

// if(left ) -1 
// if(right) +1
// if(stay ) +0
int mod = 1e9+7;

    int dfs(int sum, int steps, int arrLen,vector<vector<int>>&dp){
        // reached out of road 
        if(sum>=arrLen || steps<0 || sum<0) return 0;
        // exhausted steps 
        if(steps==0){
            // reached end of arrlen or exhauseted steps 
            if(sum==0) return 1;
            else return 0;
        }
        // cout<<steps<<endl;
        if(sum>=0 && steps>=0 && dp[sum][steps]!=-1) return dp[sum][steps];

        // left
        int left = (sum-1)%mod;
        int leftways = dfs(left,steps-1,arrLen,dp);
        // right
        int right = (sum+1)%mod;
        int rightways = dfs(right,steps-1,arrLen,dp);
        // stay
        int stayways = dfs(sum,steps-1,arrLen,dp);

        dp[sum][steps]=((leftways+rightways)%mod+stayways)%mod;
        return dp[sum][steps];
    }
};
