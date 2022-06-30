class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size()==1) return 0;
        sort(nums.begin(),nums.end());
        
//         int mid = nums[nums.size()/2];
        
//         int ans=0;
//         for(auto ele : nums){
//             ans+=abs(mid-ele);
//         }
        // OR 
        int i=0, j=nums.size()-1;
        int ans=0;
        while(i<j){
            ans += nums[j--]-nums[i++]; 
        }
        return ans;
    }  
};
