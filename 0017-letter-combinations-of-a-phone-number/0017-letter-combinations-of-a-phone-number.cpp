class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>v;
        v.push_back("");
        for(int i=0;i<digits.size();i++){
            string t = "";
            switch (digits[i]){
                case '2': 
                    t="abc";
                    break;
                case '3':
                    t="def";
                    break;
                case '4':t="ghi";break;
                case '5':t="jkl";break;
                case '6':t="mno";break;
                case '7':t="pqrs";break;
                case '8':t="tuv";break;
                case '9':t="wxyz";break;
}
            vector<string>tt;
            for(auto et:t){
                for(auto ev:v){
                    ev = ev+et;
                    tt.push_back(ev);
                }
            }
            v=tt;
        }

        return v;
    }
};