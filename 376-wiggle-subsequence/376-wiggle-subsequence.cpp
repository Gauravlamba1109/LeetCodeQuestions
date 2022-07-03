class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        bool p = true; int cntp=0;
        bool n = true; int cntn=0;
        
        for(int i=0;i<nums.size()-1;i++){
            // cout<<dif[i]<<" -> ";
            if( (p & nums[i+1]>nums[i]) || (!p & nums[i+1]<nums[i]) ){ 
                cntp++;
                p=!p;
            }
            
            if( (n & nums[i+1]<nums[i]) || (!n & nums[i+1]>nums[i]) ){ 
                cntn++;
                n=!n;
            }
            
            // cout<<cntp<<" "<<cntn<<endl;
        }
        return max(cntn,cntp)+1;
    }
};