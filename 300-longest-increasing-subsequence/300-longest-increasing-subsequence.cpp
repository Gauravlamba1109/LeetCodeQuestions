class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return helper(nums,nums.size()-1);
    }
    
    int helper(vector<int>&nums,int i){
        vector<int>dp(nums.size(),1);
        
        for(int i=nums.size()-1;i>=0;i--){
            int maxi=0;
            for(int j=i; j<nums.size();j++){
                if(nums[j]>nums[i])
                    maxi = max(maxi,dp[j]);
            }
            dp[i]=maxi+dp[i] ;
        }
        // int ans=0;
        for(int i=0;i<dp.size();i++)cout<<dp[i]<<" ";
        cout<<endl;
        return *max_element(dp.begin(),dp.end());
    }
};