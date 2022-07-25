class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // nlogn
        vector<int>res=nums;
        sort(res.begin(),end(res));
        int ir = res.size()-1;
        
        for(int i=1;i<nums.size();i+=2) nums[i]=res[ir--];
        for(int i=0;i<nums.size();i+=2) nums[i]=res[ir--];

    }
};