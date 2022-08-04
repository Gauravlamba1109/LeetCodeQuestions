class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans=0;
        for(auto ele: nums){
            ans^=ele;
        }
        return ans;
    }
};