class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot = 0;
        for(auto e: nums) tot+=e ;
        if(tot%2 != 0) return false;

        return hel(nums,tot/2,0);
    }

    bool hel(vector<int>&nums,int w, int i){
/*
// rec
        if(i>=nums.size()) return false;
        if(w<0) return false;
        if(w==0) return true;

        if(hel(nums,w-nums[i],i+1) || hel(nums,w,i+1)) return true;

        return false;
*/

// dp

// dp[]
        vector<vector<bool>>dp(nums.size()+1,vector<bool>(w+1,false));
        for(int i=0;i<nums.size();i++) dp[i][0]=true; // if w=0 then true for all sizes 

        for(int i=1;i<=nums.size();i++){
            for(int j=0;j<=w;j++){
                bool a = (i-1>=0)?dp[i-1][j]: false;
                bool b = (i-1>=0 && j-nums[i-1]>=0)?dp[i-1][j-nums[i-1]]:false;
                // we can say that nums[i-1] is the curr element 
                // i is the number of elements 
                dp[i][j] = a || b;
            }
        }

        return dp[nums.size()-1][w];
    }
};


