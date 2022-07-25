class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        //juest greater 
        int l = 0;
        int h = nums.size()-1;
        int m;
        
        while(l<h){
            m = l + ( h-l )/2;
            if(target > nums[m] ){
                l = m+1;
            }else{
                h = m;
            }
        }
        if(nums[l]!=target) return {-1,-1};
        int left = l;
        
        //just less
        h= nums.size()-1;
        
        while(l<h){
            m = l + ( h-l +1 )/2;
            
            if(target< nums[m] ) h = m-1;
            else l = m ;
        }
        
        vector<int>v{left,h};
        return v;
        
    }
};