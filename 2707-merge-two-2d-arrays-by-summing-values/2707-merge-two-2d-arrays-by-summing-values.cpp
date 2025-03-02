class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> hm;
        for(int i=0;i< max(nums1.size(),nums2.size()) ; i++){
            if(i<nums1.size()){ hm[nums1[i][0]]=hm[nums1[i][0]]+nums1[i][1]; 
            // cout<<nums1[i][0]<<" "<<nums1[i][1]<<" "<<hm[nums1[i][0]]<<endl;
            }
            if(i<nums2.size()){ hm[nums2[i][0]]=hm[nums2[i][0]]+nums2[i][1]; 
            // cout<<nums2[i][0]<<" "<<nums2[i][1]<<" "<<hm[nums2[i][0]]<<endl;
            }
        }

        // for(auto e:nums1) hm[e[0]]=e[1];
        // for(auto e:nums2) hm[e[0]]+=e[1];

        vector<vector<int>> ma;
        for(auto e: hm) ma.push_back({e.first,e.second});
        return ma;
    }
};