class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        for(auto &ele:nums)if(ele<0)ele=0;
        
        while(i<nums.size()){
            if(nums[i]>0 && nums[i]<nums.size() && nums[i]!=nums[nums[i]-1] ){
                swap(nums[i],nums[nums[i]-1]);
            }else i++;
        }
        // for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
        // cout<<endl;
        
        int ans = nums.size()+1;
        for(auto ele:nums)if(ele==0)ans--;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1) return i+1 ; 
        }
        return ans;

        
        
//         if(nums.size()==1) {
//             if(nums[0]==1) return 2; 
//             else if(nums[0]>=2) return 1; 
//         }
//         // we dont care for -ve intergers 
        
//         int ans = nums.size()+1;
        
//         for(auto & ele : nums){
//             if(ele<=0){
//                 ele=1e9;
//                 ans=ans-1;
//             }
//         }
        
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==1e9)continue;
//             if((abs(nums[i])-1)>=nums.size()) continue;
//             nums[abs(nums[i])-1]= -1* abs(nums[abs(nums[i])-1]) ;
//         }
        
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]>0) ans=min(ans,i+1);
//         }
//         return ans;
    }
};