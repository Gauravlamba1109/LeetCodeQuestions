class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>>dp(d+1,vector<int>(target+1,0));
        dp[0][0]=1;
        int mod=1000000007;
        for(int i=1;i<d+1;i++){
            for(int j=1;j<target+1;j++){
                if(j>i*f)continue;
                else{
                    for(int k=1;k<=f && k<=j;k++){
                        dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod;
                    }
                }
            }
        }
        return dp[d][target];
    }
};