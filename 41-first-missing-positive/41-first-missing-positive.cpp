class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==1) {if(nums[0]==1) return 2; else if(nums[0]>=2) return 1; }
        // we dont care for -ve intergers 
        int ans = nums.size()+1;
        for(auto & ele : nums){
            if(ele<=0){
                ele=1e9;
                ans=ans-1;
            }
        }
        // cout<<ans<<"-> ";
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1e9)continue;
            int ind = abs(nums[i])-1;
            if(ind>=nums.size()) continue;
            int to = -1* abs(nums[ind]);
            nums[ind]= to ;
        }
        // for(auto ele:nums)cout<<ele<<" ";
        // cout<<endl;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0) continue;
            if(nums[i]>0) ans=min(ans,i+1);
            if(nums[i]==1e9) ans = min(ans,i+1);
            // cout<<" ; "<<i<<" "<<nums[i]<<"-"<<ans;
        }
        // cout<<endl;
        return ans;
    }
};