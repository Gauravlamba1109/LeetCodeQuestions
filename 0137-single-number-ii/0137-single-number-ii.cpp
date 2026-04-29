class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // brute count all return one with 1 occ
        // use a hash map to count 
        // count with %3 
        // 

        unordered_map<int,int> m ;
        for(auto e : nums){
            if(m.contains(e)) continue;
            int i = count(nums.begin(),nums.end(),e)%3;
            if(i==1) return e;
            m[e]=1;
        }

        return -1;
    }
};