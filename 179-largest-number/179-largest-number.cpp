class Solution {
public:
    string largestNumber(vector<int>& n) {
        vector<string>nums;
        for(auto &ele:n)nums.push_back(to_string(ele));
        
        sort(nums.begin(),nums.end(), [](const string &a , const string & b){
            if(a+b > b+a) return true;
            else return false;
        });
        string ans="";
        for(auto e:nums)ans+=e;
        if(ans[0]=='0') return "0";
        return ans;
    }
};