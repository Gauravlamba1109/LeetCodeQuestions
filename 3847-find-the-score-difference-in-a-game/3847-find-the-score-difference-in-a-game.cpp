class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        // simulation
        int fscore=0;
        bool fturn = 1;
        for(int i=0;i<nums.size();i++){
            
            if((nums[i]%2==1)){ 
                fturn = (fturn==1)?0:1;
            }
            if(i%6==5){
                fturn = (fturn==1)?0:1;
            }

            if(fturn){
                fscore+=nums[i];
            }else{
                fscore-=nums[i];
            }
        }

        return fscore;
    }
};