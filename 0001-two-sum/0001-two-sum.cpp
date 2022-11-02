class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            int tofind = target-nums[i];
            vector<int>::iterator it;
            it = find(nums.begin()+i+1,nums.end(),tofind);
            if( it != nums.end() ) return {i,(int)(it-nums.begin())};
        }
        return {};
    }
};