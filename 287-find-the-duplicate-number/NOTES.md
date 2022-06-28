class Solution {
public:
int findDuplicate(vector<int>& nums) {
// Floyd's algorithm for detecting a loop (when we are stuck within duplicate values)
if (nums.size() > 1) {
int slow = nums[0];
int fast = nums[nums[0]];
while (slow != fast) {
slow = nums[slow];
fast = nums[nums[fast]];
}
// slow becomes equal to fast only when they encounter a duplicate value
// to find out the point of meeting 'x', traverse fast from 0 to 'x' and slow from its current position to 'x'
// when again, fast = slow, point of meeting (duplicate value) is determined
fast = 0;
while (fast != slow){
fast = nums[fast];
slow = nums[slow];
}
return slow;
}
return -1;
}
};