class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // finding the peaks just next edges k and l ; 
        // such that k is always ahead of peak 
        // but l can be peak 
        // l should have value greater than k 
        // so that we can get a just greater number at k after swap 
        // to get the next permutation ; after swap sort the ele after peak 
        int n = nums.size(), k , l;
        
        for(k=n-2; k>=0 ; k--){
            if(nums[k]<nums[k+1]) break;
        }
        if(k<0){
            reverse(nums.begin(),nums.end());
        }else{
            for(l=n-1; l>k ; l--){
                if(nums[l]>nums[k]) break;
            }
            
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
    }
};