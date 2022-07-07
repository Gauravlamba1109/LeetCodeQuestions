class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //bit mainu
        int n=nums[0];
        for(int i=1;i<nums.size();i++){
            n^=nums[i];
        }
        return n;
    }
};