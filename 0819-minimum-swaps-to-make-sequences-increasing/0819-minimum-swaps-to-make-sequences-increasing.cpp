class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp (2,vector<int>(nums1.size(),-1));
        return dfs(nums1, nums2, -1,-1,0,0,dp);
    }

    int dfs(vector<int>& nums1, vector<int>& nums2, int prev1, int prev2, int i, int swapped,vector<vector<int>>&dp){
        if(i==nums1.size()) return 0;

        if( dp[swapped][i]!=-1) return dp[swapped][i];
        int S = INT_MAX;
        if(nums2[i] > prev1 && nums1[i] > prev2 ){
            // we passs only the curr swapped as prev ele 
            // we pass swapped as 1 to indicate its swapped 
            // we can just pass swapped and not prev1 and prev2 as they can be taken based on swapped or not value
            S = 1 + dfs(nums1, nums2, nums2[i], nums1[i], i+1, 1,dp);
        }
        
        int NS = INT_MAX;
        if(nums2[i] > prev2 && nums1[i] > prev1 ){
            NS = dfs(nums1, nums2, nums1[i], nums2[i], i+1, 0,dp);
        } 

        dp[swapped][i] = min(S,NS);
        return dp[swapped][i];
    }
};