```
class Solution {
public:
int dp[1001][501];
int func(int i, int n, vector<int> &arr)
{
if(i >= arr.size() || n == 0) return 0;
if(dp[i][n] != -1) return dp[i][n];
return dp[i][n] = max(func(i + 1,n,arr),func(i + 2,n - 1,arr) + arr[i]);
}
int maxSizeSlices(vector<int>& slices)
{
int n = slices.size();
memset(dp,-1,sizeof(dp));
int ans1 = func(1,n/3,slices);
memset(dp,-1,sizeof(dp));
slices[n - 1] = 0;
int ans2 = func(0,n/3,slices);
return max(ans1,ans2);
}
};
```