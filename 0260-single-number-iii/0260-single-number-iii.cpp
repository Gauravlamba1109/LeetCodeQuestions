class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // xor will cancel duplicate number 
        // last we will have xor of two numbers 

        int x=nums[0];
        for(int i=1;i<nums.size();i++) x=x^nums[i];

// get xor 
// 2nd phase is to find the two number 
// simple : find the first bit that is set in your xor 
// at this place both the numbers are different 
// so place all numbers with this bit set in group a 
// and not set in group b 
// group ka xor will give a, as all other duplicates will cancel each other 

        int a=0,b=0;
        unsigned int rightmostsetbit = x & -(unsigned int)x; 
        for(int i=0;i<nums.size();i++){
            unsigned int t1 = rightmostsetbit & nums[i] ;
            if(t1 & -t1 ) a^=nums[i];
            else b^=nums[i];
        }

        return {a,b};
    }
};

