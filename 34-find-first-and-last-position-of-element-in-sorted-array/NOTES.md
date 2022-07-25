vector<int> ans{};
auto d = find(nums.begin(),nums.end(),target);
if (d == nums.end()) {
return {-1,-1};
}
ans.push_back(d - nums.begin());
auto r = d;
auto prv = r;
while (r != nums.end()) {
prv = r;
int idx = (r - nums.begin()) + 1;
r = find((nums.begin() + idx ), nums.end(), target );
}
ans.push_back((prv - nums.begin()) );
return ans;
}
};
​
​
class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
auto it1 = lower_bound(begin(nums), end(nums), target);
auto it2 = upper_bound(it1, end(nums), target);
if(it1 == end(nums) || *it1 != target)
{
return {-1, -1};
}
int start = it1 - begin(nums);
int end =   it2 - begin(nums);
return {start, end-1};
}
};