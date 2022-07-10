class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>r(height.size());
        vector<int>l(height.size());
        
        for(int i=0,j=height.size()-1;i<height.size(),j>=0;i++,j--){
            if(j==height.size()-1)
                r[j]=height[j];
            else{
                r[j]=max(height[j],r[j+1]);
            }
            
            if(i==0)
                l[i]=height[0];
            else{
                l[i]=max(height[i],l[i-1]);
            }
        }
        vector<int>dp(height.size(),0);
        for(int i=1;i<height.size()-1;i++){
            dp[i]= max(min(r[i],l[i])-height[i],0);
        }
        
        return accumulate(dp.begin(),dp.end(),0);
    }
};