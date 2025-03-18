class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int usedbits = 0;
        int start = 0 ;
        int ans = 0;
        for(int end=0;end<nums.size();end++){
            // till not valid decrease window size with end
            while((usedbits & nums[end]) !=0 ){
                // remove starting 
                usedbits ^= nums[start];
                start++;
            }

            usedbits |= nums[end];

            ans = max(ans,end-start+1);
        }
        return ans;
    }
};