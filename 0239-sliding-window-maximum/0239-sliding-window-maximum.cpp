class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    map<int, int> freq;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;

        if (i >= k) {
            int out = nums[i - k];

            freq[out]--;

            if (freq[out] == 0) {
                freq.erase(out);
            }
        }

        if (i >= k - 1) {
            ans.push_back(freq.rbegin()->first);
        }
    }

    return ans;
    }
};