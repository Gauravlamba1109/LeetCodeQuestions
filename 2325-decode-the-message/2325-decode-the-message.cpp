class Solution {
public:
    string decodeMessage(string key, string message) {
        string ans="";
        unordered_map<char,char>m;
        int k=0;
        for(int i=0;i<key.size();i++){
            char c = key[i];
            if(c ==' ')continue;
            if(m.find(c)==m.end()) m[c]= 'a'+ k++;
            if(m.size()>25) break;
        }
        
        for(int i=0;i<message.size();i++){
            char c = message[i];
            if(c==' ')ans+=' ';
            else ans+= (char)m[c];
        }
        return ans;
    }
};