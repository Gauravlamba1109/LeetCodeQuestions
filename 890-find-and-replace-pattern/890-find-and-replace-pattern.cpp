class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        
        // for(auto w : words){
        //     if(match(w,pattern))ans.push_back(w);
        // }
        
        // or 
        string p = f(pattern);
        for(auto w : words){
            if(f(w)==p)ans.push_back(w);
        }
        return ans;
    }
    
    
    string f(string w){
        unordered_map<char,int>m;
        for(auto c : w){
            if(m.find(c)==m.end()) m[c]=m.size();
        }
        for(auto &c : w){
            c = 'a'+m[c];
        }
        return w ; 
    }
    
//     bool match(string w,string pattern){
//         map<char,char>m1;
//         map<char,char>m2;
        
//         for(int i=0;i<w.size();i++){
//             char a = w[i];
//             char b = pattern[i];
            
//             if(m1.find(a)==m1.end()) m1[a]=b;
//             if(m2.find(b)==m2.end()) m2[b]=a;
            
//             if(m1[a]!=b || m2[b]!=a) return false;
//         }
//         return true;
//     }
};