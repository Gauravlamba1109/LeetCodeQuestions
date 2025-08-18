class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string,int>>sym = {
            {"I",1},{"IV",4},{"V",5},{"IX",9},
            {"X",10},{"XL",40},{"L",50},{"XC",90},
            {"C",100},{"CD",400},{"D",500},{"CM",900},
            {"M",1000}
        };
        string ans="";

        int n = sym.size();
        for(int i=n-1; i>=0; i--){
            int d = num/sym[i].second;
            int rem = num%sym[i].second;

            while(d--){
                ans+=sym[i].first;
            }

            num=rem;
        }

        return ans;
    }
};