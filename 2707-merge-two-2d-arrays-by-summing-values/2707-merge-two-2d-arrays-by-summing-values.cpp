class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> hm;
        for(auto e:nums1) hm[e[0]]=e[1];
        for(auto e:nums2) hm[e[0]]+=e[1];

        vector<vector<int>> ma;
        for(auto e: hm) ma.push_back({e.first,e.second});
        return ma;
    }
};