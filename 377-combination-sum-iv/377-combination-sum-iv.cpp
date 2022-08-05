class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        if(target==0) return 1;
        dp[0]=1;
        return solve(nums,target,dp);
    }
    
    int solve(vector<int>&nums,int target,vector<int>&dp){
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(target>=nums[i]){
                ans+=solve(nums,target-nums[i],dp);
            }
        }
        dp[target]=ans;
        return dp[target];
    }
};