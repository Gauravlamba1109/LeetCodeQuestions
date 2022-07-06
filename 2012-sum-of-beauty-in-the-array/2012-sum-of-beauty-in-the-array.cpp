class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int>left(nums.size(),0);
        vector<int>right(nums.size(),0);
        int last = nums.size()-2;
        int ma = nums[0];
        int mi = nums[last+1];
        left[0]=nums[0];
        right[last+1]=nums[last+1];
        
        for(int i=1, j=last ;i<nums.size() && j>=1 ;i++, j--){
            left[i]=ma;
            if(nums[i]>ma) ma=nums[i];
            
            right[j]=mi;
            if(nums[j]<mi) mi=nums[j];
            
        }
        // for(auto e : left)cout<<e<<" ";
        // cout<<endl;
        // for(auto e : right)cout<<e<<" ";
        // cout<<endl;
        int ans=0;
        for(int i=1;i<=nums.size()-2;i++){
            if( left[i]<nums[i] && right[i]>nums[i]) ans+=2;
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1]) ans+=1;
            else ans+=0;
        }
        return ans;
    }
};