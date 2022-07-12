}
bool btrack(vector<int>& nums, int target, int i, int k) {
if (k == 1)
return true;
for (; i < nums.size(); i++) {
int num = nums[i];  // stored for further restoring state of nums[i]
bool res;
if (num > target)   // if current number is greater, we can't include it, so skip
continue;
nums[i] = req + 1;  // element moved out of range so that it won't be used again
if (num == target)  // target is found which means current subset is full, move to next one, with target = required, index as 0 and next subset k-1
res = btrack(nums, req, 0, k-1);
else
res = btrack(nums, target-num, i+1, k);
if (res)
return true;
nums[i] = num;
while (i < nums.size()-1 and nums[i+1] == num)
i++;        // skip all the duplicate elements which couldn't produce an answer, it'll reduce time complexity
}
return false;
}
};