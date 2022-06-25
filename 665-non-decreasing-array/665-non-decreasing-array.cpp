class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool f = false;
        
        for(int i=0;i<nums.size(); i++){
            if((i==nums.size()-1) or( (i+1)<nums.size() && nums[i]<=nums[i+1])) continue;
            if(f) return false;
            
            if( i==0 or ( i+1<nums.size() && nums[i-1]<=nums[i+1] )){
                nums[i]=nums[i+1];
                f=1; 
            }else if((i+1)<nums.size()){ 
                nums[i+1]=nums[i];
                f=1;
            }
        }
        
        return true;
    }
};