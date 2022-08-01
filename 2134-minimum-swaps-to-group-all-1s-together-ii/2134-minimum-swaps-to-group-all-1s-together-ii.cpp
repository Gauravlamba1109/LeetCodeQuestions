class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // make a sliding window equal to size 
        // size = no of one pr in nums 
        // and count the no of 0s in the window 
        // take the min of this cnt in each window 
        // return the ans 
        // we count the no of 0s because that is 
        // the number of positions we have to update to club 1s
        // together 
        
     
        int i=0;
        int j= accumulate(begin(nums),end(nums),0);
        if(j==0) return 0;
        j--;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        
        int zeros=0;
        int mini=INT_MAX;
        for(int k=0;k<=j;k++)zeros+=(nums[k]==0)?1:0;
        mini = zeros;
        j++;
        while( j<nums.size() ){
            if(nums[j]==0){
                zeros++;
            }
            if(nums[i]==0){
                zeros--;
            }
            mini=min(mini,zeros);
            i++;
            j++;
        }
        
        return mini;
    }
};