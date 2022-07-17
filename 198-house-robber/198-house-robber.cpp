class Solution {
public:
    int rob(vector<int>& nums) {
        vector m(nums.size()+1,-1);
        
        return helper(nums,nums.size()-1,m);
    }
    
//     int helper(vector<int>&nums, int i,vector<int>&m){
//         if(i>=nums.size()) return 0;
        
//         if(m[i]>=0) return m[i];
        
//         int inc = nums[i]+helper(nums,i+2,m);
//         int noc = helper(nums,i+1,m);
        
//         return m[i]=max(inc,noc);
//     }
    
    
    int helper(vector<int>&nums,int i,vector<int>&m){
        if(i>=nums.size()) return 0;
        if(m[i]!=-1) return m[i];
        return m[i]=max( nums[i]+helper(nums,i-2,m),helper(nums,i-1,m) );
    }
};