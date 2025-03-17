class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto e : nums){
            m[e]++;
        }
        for(auto e : m){
            if(e.second%2 != 0) return false;
        }

        return true;
    }
};