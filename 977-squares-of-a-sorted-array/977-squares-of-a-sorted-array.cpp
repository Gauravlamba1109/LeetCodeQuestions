class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        sort(nums.begin(),nums.end(), [](const int & a , const int & b){
            return abs(a)<abs(b);
        });
        
        for(auto &e : nums)e*=e;
        return nums;
        
//         int s=0;
//         int e=nums.size()-1;
        
//         vector<int>ans(nums.size(),0);
        
//         for(int k=nums.size()-1 ; k>=0 ; k--){
//             if(abs(nums[e])>abs(nums[s])){ 
//                 ans[k]=nums[e]*nums[e];
//                 e--;
//             }else{
//                 ans[k]=nums[s]*nums[s];
//                 s++;
//             }
            
//         }
        
//         return ans;
    }
};