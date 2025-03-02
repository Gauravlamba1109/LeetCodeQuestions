class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> hm;
        int x = max(nums1.size(),nums2.size());
        for(int i=0;i< x ; i++){
            if(i<nums1.size()) hm[nums1[i][0]]=hm[nums1[i][0]]+nums1[i][1]; 
            if(i<nums2.size()) hm[nums2[i][0]]=hm[nums2[i][0]]+nums2[i][1]; 
        }

        vector<vector<int>> ma;
        for(auto e: hm) ma.push_back({e.first,e.second});
        return ma;
    }
};