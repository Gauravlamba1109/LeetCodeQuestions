class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        map<int,int>m;
        for(int i=nums.size()-1; i>=0;i--){
            int e=nums[i];
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