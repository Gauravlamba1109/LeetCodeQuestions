public int minCostClimbingStairs(int[] cost) {
int n = cost.length;
int[] dp = new int[n];
for (int i=0; i<n; i++) {
if (i<2) dp[i] = cost[i];
else dp[i] = cost[i] + Math.min(dp[i-1], dp[i-2]);
}
return Math.min(dp[n-1], dp[n-2]);
}
​
Step 5 - Optimization 3 - Fine Tuning - Reduce O(n) space to O(1).
​
// Bottom up computation - O(n) time, O(1) space
public int minCostClimbingStairs(int[] cost) {
int n = cost.length;
int first = cost[0];
int second = cost[1];
if (n<=2) return Math.min(first, second);
for (int i=2; i<n; i++) {
int curr = cost[i] + Math.min(first, second);
first = second;
second = curr;
}
return Math.min(first, second);
}
​
class Solution {
public:
int minCostClimbingStairs(vector<int>& cost) {
int n=cost.size();
if(n==0) return 0;