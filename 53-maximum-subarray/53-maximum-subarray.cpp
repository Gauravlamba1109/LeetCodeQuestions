class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadanes algo 
        int currsum = nums[0];
        int maxsum = nums[0];
        for(int i=1;i<nums.size();i++){
            currsum = max(currsum+nums[i],nums[i]);
            maxsum = max(maxsum,currsum);
        }
        
        return maxsum ;
    }
};



// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n=nums.size();
//         if (n==1)
//             return nums[0];
//         int max_till=nums[0];
//         int sum=nums[0];
//         for(int i=1;i<n;i++)
//         {
//             sum=sum+nums[i];
//             sum=max(sum,nums[i]);
//             max_till=max(max_till,sum);
//         }
//         return max_till;
//     }
// };