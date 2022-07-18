```
vector<vector<int> > subsetsWithDup(vector<int> &S) {
vector<vector<int> > totalset = {{}};
sort(S.begin(),S.end());
for(int i=0; i<S.size();){
int count = 0; // num of elements are the same
while(count + i<S.size() && S[count+i]==S[i])  count++;
int previousN = totalset.size();
for(int k=0; k<previousN; k++){
vector<int> instance = totalset[k];
for(int j=0; j<count; j++){
instance.push_back(S[i]);
totalset.push_back(instance);
}
}
i += count;
}
return totalset;
}
```
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
vector<vector<int>>ans;
vector<int>tans;
sort(nums.begin(),nums.end());
helper(ans,tans,nums,0);
return ans;
}
void helper(vector<vector<int>>&ans,vector<int>tans,vector<int>&nums,int st){
ans.push_back(tans);
for(int i=st;i<nums.size();i++){
if(i!=st &&nums[i-1]==nums[i])continue;
tans.push_back(nums[i]);
helper(ans,tans,nums,i++);
tans.pop_back();
}
}
​