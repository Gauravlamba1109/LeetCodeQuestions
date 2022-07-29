class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int>m;
        
        for(auto c:s){
            if(m.find(c)==m.end())m[c]=m.size();
        }
        for(auto &c:s) c = 'a'+ m[c];
        
        m.clear();
        for(auto c:t){
            if(m.find(c)==m.end())m[c]=m.size();
        }
        for(auto &c:t) c = 'a'+ m[c];
        
        return s==t;
    }
};