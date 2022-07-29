class Solution {
public:
    bool wordPattern(string pattern, string s) {
        //check size first 
//         vector<string>dum;
//         stringstream t(s); string tt;
//         while(t>>tt)dum.push_back(tt);
        
//         if(pattern.size()!=dum.size())return false;
        
//         map<string,char>s2c;
//         map<char,string>c2s;
        
//         for(int i=0;i<pattern.size();i++){
//             if( s2c[dum[i]]==0 && c2s[pattern[i]]=="" ){
//                 s2c[dum[i]]=pattern[i];
//                 c2s[pattern[i]]=dum[i];
//                 continue;
//             }
//             if( s2c[dum[i]]!=pattern[i]) return false;
//         }
        
//         return true;
        
        
        
        unordered_map<char,int>m1;
        unordered_map<string,int>m2;
        
        stringstream ss(s);
        
        int i=0; int n = pattern.size();
        
        for(string word ; ss>>word ; i++){
            if(i==n || m1[pattern[i]]!=m2[word]) return false;
            m1[pattern[i]]= i+1;
            m2[word]= i+1;
        }
        
        return i==n;
    }
};