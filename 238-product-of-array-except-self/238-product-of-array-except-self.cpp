class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size(),1);
        // use ans for prefix 
        for(int i=1;i<nums.size();i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        int post= 1;
        for(int i=nums.size()-1;i>=0 ; i--){
            ans[i]=post*ans[i];
            post=post*nums[i];
        }
        return ans;
    }
};