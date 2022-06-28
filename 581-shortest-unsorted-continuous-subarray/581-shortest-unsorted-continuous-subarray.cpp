class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        if(nums.size()==1) return 0;
        int ma=nums[0];
        int mi = nums[nums.size()-1];
        int start = -1;
        int end = -2;
        
        //longest unsorted subarray 
        for(int i=1;i<nums.size();i++){
            int j=nums.size()-1-i;
            
            ma = max(ma,nums[i]);
            if(ma>nums[i]){
                end = i;
            } 
            mi = min(mi,nums[j]);
            if(mi<nums[j]){
                start = j;
            }
        }

        return end-start+1;
    }
};

// 2,6,4,8,10,9,15
// . . | .  . |  . 
// . | . .  | .  .
    
    