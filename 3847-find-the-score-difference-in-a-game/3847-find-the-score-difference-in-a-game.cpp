class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        // simulation
        int fscore=0;
        bool fturn = 1;
        for(int i=0;i<nums.size();i++){
            
            if((nums[i]%2==1)){ 
                fturn = !fturn;
            }
            if(i%6==5){
                fturn = !fturn;
            }

            fscore = fturn?fscore+nums[i]:fscore-nums[i];
        }

        return fscore;
    }
};