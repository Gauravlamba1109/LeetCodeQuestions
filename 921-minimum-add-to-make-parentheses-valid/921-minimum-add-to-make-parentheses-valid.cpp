class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int ans = 0;
        for(auto c:s){
            if(c=='(')open++;
            if(c==')'){
                if(open>0)open--;
                else{
                    ans++;
                }
            }
        }
        return abs(open)+ans;
    }
};