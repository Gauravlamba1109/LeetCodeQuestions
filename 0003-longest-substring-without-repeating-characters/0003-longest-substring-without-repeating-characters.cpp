class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1) return s.size();
        set<char>se;
        se.insert(s[0]);
        int i=0;
        int m = 1;
        for(int j=i+1;j<s.size();j++){
            while(se.contains(s[j]) ){
                se.erase(s[i]);
                i++;
            }
            m=max(m,j-i+1);
            se.insert(s[j]);

        }

        return m;
    }
};