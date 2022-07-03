class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        vector<int>dif;
        for(int i=0;i<nums.size()-1;i++){
            dif.push_back(nums[i+1]-nums[i]);
        }
        
        int startingpos = 0; bool p = true; int cntp=0;
        int startingneg = -1;bool n = true; int cntn=0;
        for(int i=0;i<dif.size();i++){
            // cout<<dif[i]<<" -> ";
            if(p){
                if(dif[i]>0){ 
                    cntp++;
                    p=false;
                }
            }
            else if(!p){
                if(dif[i]<0){ 
                    cntp++;
                    p=true;
                }
            }
            
            if(n){
                if(dif[i]<0){ 
                    cntn++;
                    n=false;
                }
            }
            else if(!n){
                if(dif[i]>0){ 
                    cntn++;
                    n=true;
                }
            }
            // cout<<cntp<<" "<<cntn<<endl;
        }
        return max(cntn,cntp)+1;
    }
};