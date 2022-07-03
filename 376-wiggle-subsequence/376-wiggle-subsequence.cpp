class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        vector<int>dif;
        for(int i=0;i<nums.size()-1;i++){
            dif.push_back(nums[i+1]-nums[i]);
        }
        
        bool p = true; int cntp=0;
        bool n = true; int cntn=0;
        for(int i=0;i<dif.size();i++){
            // cout<<dif[i]<<" -> ";
            if((p & dif[i]>0)|| (!p & dif[i]<0)){ 
                cntp++;
                p=!p;
            }
            
            if((n & dif[i]<0) || (!n & dif[i]>0)){ 
                cntn++;
                n=!n;
            }
            
            // cout<<cntp<<" "<<cntn<<endl;
        }
        return max(cntn,cntp)+1;
    }
};