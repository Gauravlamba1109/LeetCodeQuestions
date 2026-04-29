class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // brute count all return one with 1 occ
        // use a hash map to count 
        // count with %3 
        // 


        unordered_map<int,int> ma;
        
        for(auto e : nums){
            ma[e]++;
            ma[e]=ma[e]%3;
        }

        for(auto e : ma){
            if(e.second==1) return e.first;
        }

        return -1;
    }
};