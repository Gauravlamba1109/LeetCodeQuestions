class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>r(height.size());
        
        for(int j=height.size()-1;j>=0 ; j--){
            if(j==height.size()-1)
                r[j]=height[j];
            else{
                r[j]=max(height[j],r[j+1]);
            }
        }
        int ans=0;
        int ma=height[0];
        
        for(int i=1;i<height.size()-1;i++){
            ma=max(height[i],ma);
            ans+= max(min(r[i],ma)-height[i],0);
        }
        
        return ans;
    }
};