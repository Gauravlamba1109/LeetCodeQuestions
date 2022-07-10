class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int mas=nums.size();
        // xor of two dupli is 0 
        // if we xor the nums eles and all eles in 1 to n 
        // all dupli becomes 0 ; 
        // we are left with the num pre in 1 to n and not in nums
        for(int i=0;i<nums.size();i++){
            mas=mas^i;
            mas=mas^nums[i];
        }
        return mas;
    }
};
    
//     for small size of nums // runtime error
//     int missingNumber(vector<int>& nums) {
//         int64_t a = 0;//<<(nums.size());
//         for(auto & ele : nums){
//             a= a| (1<<ele);
//         }
//         for(int i=0;i<=nums.size();i++){
//             if( ((a>>i)&1)==0 )return i;
//         }
//         return a;
//     }