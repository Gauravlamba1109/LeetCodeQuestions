class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int smallest = nums[0];
        int largest = nums.back();
        
        int diff = largest-smallest;
        for(int i=0;i<nums.size()-1; i++){
            int a = nums[i];
            int b = nums[i+1];
            
            diff = min(diff, max(largest-k,a+k) - min(smallest+k,b-k));
        }
        return diff;
    }
};