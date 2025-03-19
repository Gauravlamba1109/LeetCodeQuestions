class Solution {
public:
    int minOperations(vector<int>& nums) {
        int f = 0 ;
        for(int i=0;i<=nums.size()-3;i++){
            if(nums[i]==0){
                for (int j = 0; j < 3; j++){
                    nums[i + j] ^= 1;
                }
                f++;
            }
        }

         for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) return -1; // Impossible case
        }
        return f;
    }
};