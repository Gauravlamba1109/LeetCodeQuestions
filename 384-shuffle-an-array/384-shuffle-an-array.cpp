class Solution {
    private:
    vector<int>original;
public:
    Solution(vector<int>& nums) {
        original=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int>v2(original);
        for(int i=0;i<original.size();i++){
            int pos = rand()%(v2.size()-i);
            swap(v2[i+pos],v2[i]);
        }
        return v2;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */