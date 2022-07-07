class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size()-1;
        if(n+1<5) return 0 ;
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        ans = nums[n]-nums[3];  // starting 3 
        ans = min(ans,nums[n-1]-nums[2]);
        ans = min(ans,nums[n-2]-nums[1]);
        ans = min(ans,nums[n-3]-nums[0]);
        
        return ans;
    }
};