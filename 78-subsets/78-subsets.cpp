class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>out;
        out.push_back({});
        if(nums.size()==0)return out;
        
        int s=0;
        for(int num :nums){
            int s = out.size();
            for(int i=0;i<s;i++){
                vector<int>set=out[i];
                set.push_back(num);
                out.push_back(set);
            }
        }
        return out;
    }
};