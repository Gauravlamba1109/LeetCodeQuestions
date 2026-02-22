class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        // simulation
        int fscore=0;
        int sscore=0;
        bool fturn = 1;
        for(int i=0;i<nums.size();i++){
            if((nums[i]%2==1)){ 
                fturn = (fturn==1)?0:1;
            }

            if((i+1)%6==0){
                fturn = (fturn==1)?0:1;
            }

            if(fturn){
                fscore+=nums[i];
            }else{
                sscore+=nums[i];
            }
        }

        return fscore-sscore;
    }
};