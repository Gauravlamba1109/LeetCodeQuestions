class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        
        if(nums.size()==1) return {nums};
        
        for(int i=0;i<nums.size();i++){
            int en = nums.back();
            nums.pop_back();
            vector<vector<int>> t = permute(nums);
            for(auto v:t){
                v.push_back(en);
                ans.push_back(v);
            }
            nums.insert(nums.begin(),en);
        }
        return ans;
    }
};