class Solution {
public:
    string removeStars(string s) {
        
        // accepeted o(n) tc and o(n) sc
        
//         string st;
//         for(auto c: s){
//             if(c=='*'){
//                 if(st.size()>0) st.pop_back();
//             }else{
//                 st.push_back(c);
//             }
//         }
        
        // o(n) tc o(1) sc
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*')j--;
            else s[j++]=s[i];
        }
        return s.substr(0,j);
    }
};