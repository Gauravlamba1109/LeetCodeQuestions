class Solution {
public:
bool canPartitionKSubsets(vector<int>& nums, int k) {
if(nums.size() == 0) {
return false;
}
int sum =0 ;
for(int i : nums) {
sum += i;
}
int target = sum/k;
vector<int> sub(k, 0);
sort(nums.begin(), nums.end(), greater<int>());
return solve(nums, sub, k, target, 0);
}
bool solve(vector<int>& nums, vector<int>& sub, int k, int target, int index) {
if(index == nums.size()) {
for(int i=1; i<sub.size(); i++) {
if(sub[i] != sub[i-1]) {
return false;
}
}
return true;
}
for(int i=0; i<k; i++) {
if(sub[i]+nums[index] > target) {
continue;
}
int j = i-1;
while(j>=0) {
if(sub[j] == sub[i]) {
break;
}
j--;
}
if(j != -1) {
continue;
}
sub[i] += nums[index];
if(solve(nums, sub, k, target, index+1)) {
return true;
}
sub[i] -= nums[index];
}
return false;
}
};