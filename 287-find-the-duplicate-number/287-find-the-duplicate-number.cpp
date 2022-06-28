class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // important to understand solution ' floyd's algorithm to detecting a loop 
        int fast=0,slow=0;
        
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast) break;
        }
        int slow2=0;       // finding the point of intersection 
        while(true){
            slow = nums[slow];
            slow2= nums[slow2];
            if(slow==slow2) return slow;
        }
        
        return 0;
        
        
    }
};