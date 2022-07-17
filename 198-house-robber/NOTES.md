class Solution {
public:
vector<vector<int>>m;
int rob(vector<int>& nums) {
m.resize(nums.size(),vector<int>(2,-1));
return hel(nums,0,true);
}
int hel(vector<int>&nums,int pos, bool cantake){
if(pos>=nums.size()) return 0;
if(m[pos][cantake]!=-1) return m[pos][cantake];
// if can take the curr
if(cantake){
return m[pos][cantake]=max(nums[pos] + hel(nums,pos+1,!cantake), hel(nums,pos+1,cantake)  );
}
// if cant take the curr
else{
return m[pos][cantake]=hel(nums,pos+1,!cantake);
}
}
};