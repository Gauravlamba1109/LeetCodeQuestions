class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // brute count all return one with 1 occ
        // use a hash map to count 
        // count with %3 
        // 


        for(auto e : nums){
            int i = count(nums.begin(),nums.end(),e)%3;
            if(i==1) return e;
        }

        return -1;
    }
};