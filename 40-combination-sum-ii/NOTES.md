temp.remove(temp.size()-1);
}
}
}
}
}
```
​
​
​
​
class Solution {
public:
vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
vector<vector<int>>ans;
vector<int>tans;
if(nums.size()==0) return ans;
sort(nums.begin(),nums.end());
he(ans,tans,nums,target,0);
return ans;
}
void he(vector<vector<int>>&ans ,vector<int>tans , vector<int>&nums,int target,int t){
if(target<0 || t>nums.size())return;
if(target==0)
ans.push_back(tans);
else{
map<int,int>ma;
for(int i=t; i<nums.size() ;i++){
if(i>t && nums[i]==nums[i-1])continue;
if(target-nums[i]>=0){
tans.push_back(nums[i]);
he(ans,tans,nums,target-nums[i],i+1);
tans.pop_back();
}
}
}
}
};