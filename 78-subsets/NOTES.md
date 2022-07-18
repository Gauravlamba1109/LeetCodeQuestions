class Solution {
public:
vector<vector<int>> subsets(vector<int>& nums) {
vector<vector<int>>ans;
vector<int>tans;
sort(nums.begin(),nums.end());
helper(ans,tans,nums,0);
return ans;
}
void helper(vector<vector<int>>&ans,vector<int>tans,vector<int>&nums,int st){
ans.push_back(tans);
for(int i=st;i<nums.size();i++){
tans.push_back(nums[i]);
helper(ans,tans,nums,i+1);
tans.pop_back();
helper(ans,tans,nums,i+1);
}
}
};