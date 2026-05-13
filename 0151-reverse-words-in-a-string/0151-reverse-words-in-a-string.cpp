class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        int i=0;
        int siz= s.size();
        string ans = "";

        while(i<siz){
            string t="";
            bool c = false;
            while(i<siz & s[i]==' ')i++;
            while(i<siz & s[i]!=' '){
                t+=s[i++];
                c=1;
            }

            if(c) st.push(t);
        }

        while(st.size()){
            ans+=st.top();
            st.pop();
            if(st.size()>0)ans+=" ";
        }

        return ans;
    }
};