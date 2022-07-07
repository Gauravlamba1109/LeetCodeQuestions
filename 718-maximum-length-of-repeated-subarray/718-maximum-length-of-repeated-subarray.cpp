class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
       
        for(int i=0;i<nums1.size();i++)dp[i][0]=0;        
        for(int i=0;i<nums2.size();i++)dp[0][i]=0;

        int ans=0;
        for(int l1=1;l1<=nums1.size(); l1++){
            for(int l2=1;l2<=nums2.size(); l2++){
                if(nums1[l1-1]==nums2[l2-1]){
                    dp[l1][l2]=dp[l1-1][l2-1]+1;
                }
                ans=max(ans,dp[l1][l2]);
            }
        }
        return ans;
    }
};