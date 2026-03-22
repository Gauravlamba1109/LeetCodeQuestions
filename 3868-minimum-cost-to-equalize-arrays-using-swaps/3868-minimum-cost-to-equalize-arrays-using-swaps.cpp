class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>a;
        for(auto e:nums1) a[e]++;
        for(auto e:nums2) a[e]--;
        int minc=0;
        for(auto e: a){
            // if freq of e in a + freq of e in b /2 is odd or e doesnt exists return -1;
            // else diff of the freq in a - freq in b = swaps needed to fix for e 
            // but what it is to be swapped with another ele so swaps to fix is /2            
            int af = e.second;
            if(af%2) return -1;
            if(af>0) minc+=(af/2);
        }
        return minc;

    }
};