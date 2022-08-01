int minSwaps(vector<int>& nums) {
int n = nums.size();
int ones = accumulate(nums.begin(),nums.end(),0);
int ans = INT_MAX;
int i=0;
int windowSum = 0;
for(;i<ones;i++){
windowSum += nums[i];
}
ans = min(ans,ones-windowSum);
for(;i<(n+ones);i++){
windowSum += nums[i%n];
windowSum -= nums[(i-ones)%n];
ans = min(ans,ones-windowSum);
}
return ans;
}