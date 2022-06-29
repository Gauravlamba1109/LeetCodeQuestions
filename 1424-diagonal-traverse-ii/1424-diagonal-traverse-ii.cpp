class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int>ans;
        
        map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                m[(i+j)].push_back(nums[i][j]);
            }
        }
        
        for(auto &v: m){
            reverse(v.second.begin(),v.second.end());
            for(auto ele : v.second){
                ans.push_back(ele);
            }
        }
        return ans;
    }
};