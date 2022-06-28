class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>ans;
        for(auto ele :nums){
            ans[ele]++;
        }
        vector<int>v;
        int n=nums.size();
        for(auto ele : ans){
            if(ele.second>n/3) v.push_back(ele.first);
        }
        return v;
    }
};