class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0 || s.size()==1) return s.size();
        
        // o(n) approach // using 2 pointer
        
        
        
        
        
        // o(2n) approach 
        // sliding window 
        set<char>se;
        int start = 0;
        int end= 1;
        se.insert(s[start]);
        int ssize = 1;
        
        while(end<s.size()){
                while(se.size()>0 && start<end && se.find(s[end])!=se.end()){
                    se.erase(s[start]);
                    start++;
                }     
                se.insert(s[end]);
                ssize = max(ssize , end-start+1 ); 
                end++;
        }
        return ssize;
    }
};