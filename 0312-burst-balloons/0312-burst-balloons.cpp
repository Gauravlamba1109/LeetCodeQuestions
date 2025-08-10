class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));
        return dfs(nums, 1, nums.size()-2,dp);
    }

    int dfs( vector<int> &nums, int l , int r,vector<vector<int>>&dp){
        if(l>r) return 0;

        if(dp[l][r]!=0) return dp[l][r];

        for(int i=l; i<=r; i++){
            // if curr is popped last 
            int cost = nums[l-1]*nums[i]*nums[r+1];
            cost =  cost + (dfs(nums, l, i-1,dp) + dfs(nums, i+1, r,dp));
            dp[l][r] = max(dp[l][r],cost);
        }
        return dp[l][r];
    }
};