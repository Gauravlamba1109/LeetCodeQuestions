class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size()==1) return 0;
        sort(nums.begin(),nums.end());
        int mid = nums[nums.size()/2];
        
        int ans=0;
        for(auto ele : nums){
            ans+=abs(mid-ele);
        }
        return ans;
    }  
};
