class Solution {
public:
int mod=1e9+7;
int findPaths(int m, int n, int mo, int I, int J) {
vector<vector<vector<int> > > dp(mo+1,vector<vector<int> >(m+1,vector<int>(n+1,-1)));
return helper(m,n,mo,I,J,dp);
}
int helper(int &m, int &n, int mo, int I, int J,vector<vector<vector<int>>>&dp){
if(I==m or I<0 or J==n or J<0 )return 1;
if(mo==0)return 0;
if(dp[mo][I][J]>=0)return dp[mo][I][J];
dp[mo][I][J]=(
(helper(m,n,mo-1,I-1,J,dp)%mod
+helper(m,n,mo-1,I+1,J,dp)%mod)%mod
+(helper(m,n,mo-1,I,J-1,dp)%mod
+helper(m,n,mo-1,I,J+1,dp)%mod)%mod
)%mod;
return dp[mo][I][J];
}
};