class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>n;
        for(auto e:nums1) n.push_back(e);
        for(auto e:nums2) n.push_back(e);
        sort(n.begin(),n.end());

        if(n.size()%2 == 1) return n[n.size()/2];

        return (n[n.size()/2-1]+n[n.size()/2])/2.0;
    }
};