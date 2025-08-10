class Solution {
public:
    int dp[301][301];
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        memset(dp,-1,sizeof(dp));

        return dfs(nums, 1, nums.size()-2);
    }

    int dfs( vector<int> &nums, int l , int r){
        if(l>r) return 0;

        if(dp[l][r]!=-1) return dp[l][r];

        for(int i=l; i<=r; i++){
            // if curr is popped last 
            int cost = nums[l-1]*nums[i]*nums[r+1];
            cost =  cost + (dfs(nums, l, i-1) + dfs(nums, i+1, r));
            dp[l][r] = max(dp[l][r],cost);
        }
        return dp[l][r];
    }
};