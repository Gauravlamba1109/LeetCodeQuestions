class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int l = s.size();
        // if all char are unique 
        if(l<=26){
            set<char>se(s.begin(),s.end());
            if(se.size()==l) return false;
        }
        
        for(int len = l/2 ; len>0 ; len--){
            if( l % len==1)continue;
            string t = s.substr(0,len);
            int i=len;
            while(i<l && s.substr(i,len)==t) i+=len;
            if( i==l )return true;
        }
        return false;
    }
};

// s.size()= l 
// l/2 ---------- 1 