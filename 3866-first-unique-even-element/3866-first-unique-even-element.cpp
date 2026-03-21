class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        map<int,int>m;
        for(auto e:nums){
            if(e%2==0){
                m[e]++;
            }
        }

        for(auto e:nums){
            if(m[e]==1) return e;
        }

        return -1;
    }
};