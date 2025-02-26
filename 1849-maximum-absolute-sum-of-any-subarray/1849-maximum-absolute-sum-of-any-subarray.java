class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int positive_sum = 0;
        int negative_sum = 0;
        int max_sum = 0;

        for(int i=0;i<nums.length; i++){
            // count till curr or choose curr 
            positive_sum = Math.max(positive_sum+nums[i], nums[i]);
            negative_sum = Math.min(negative_sum+nums[i], nums[i]);

            max_sum = Math.max( max_sum, Math.abs(positive_sum));
            max_sum = Math.max( max_sum, Math.abs(negative_sum));
            
        }

        return max_sum;
    }
}