class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        vector<string>reso={
            "","abc","def",
            "ghi","jkl","mno",
            "pqrs","tuv","wxyz"
        };
        vector<string>result;
        result.push_back("");
        for(auto dig : digits){
            vector<string>tmp;
            for(auto ele : reso[(dig-'0')-1]){
                for(auto s : result){
                    tmp.push_back(s+ele);
                }
            }
            result=tmp;
            tmp.clear();
        }
        return result;
    }
};