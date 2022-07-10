class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        while(i<j && j<nums.size()){
            while(j<nums.size() && nums[i]==nums[j]){
                j++;
            }
            if(i+1<nums.size() && j<nums.size()){
                nums[i+1]=nums[j];
                i++;
                j++;
            }
        }
        return i+1;
    }
};