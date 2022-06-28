Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
Find the largest index l > k such that nums[k] < nums[l].
Swap nums[k] and nums[l].
Reverse the sub-array nums[k + 1:].
​
```
​
class Solution {
public:
void nextPermutation(vector<int>& nums) {
int j=nums.size()-2;
while(j>=0 && nums[j+1]<=nums[j])j--;
if(j>=0){
int i=nums.size()-1;
//find number just larger than the nums[k]
while(nums[j]>=nums[i]) i--;
swap(nums[i],nums[j]);
}
rev(nums,j+1);
}
void rev(vector<int>& nums, int start){
int i=start , j = nums.size()-1;
while(i<j){
swap(nums[i],nums[j]);
i++; j-- ;
}
}
};
​
```
​
​
Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
Find the largest index l > k such that nums[k] < nums[l].
Swap nums[k] and nums[l].
Reverse the sub-array nums[k + 1:].
```
​
class Solution {
public:
void nextPermutation(vector<int>& nums) {
int n = nums.size(), k, l;
for (k = n - 2; k >= 0; k--) {
if (nums[k] < nums[k + 1]) {
break;