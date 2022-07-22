class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i=0;
        int j=0;
        int len=0;
        
        // we will insert them in multiset because duplicates 
        // might be pr. and we wnat to keep them sorted 
        // if limit exceeds we can delete nums[i] from set 
        
        multiset<int>se;
        while(i<=j && j<nums.size()){
            se.insert(nums[j]);
            while(i<=j && abs(*se.begin()-*se.rbegin())>limit){
                se.erase(se.find(nums[i]));
                i++;
            }
            len = max(len,j-i+1);
            j++;
        }
        
        return len;
    }
};