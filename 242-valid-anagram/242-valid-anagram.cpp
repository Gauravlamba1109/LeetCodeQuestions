class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[27]={0};
        for(auto c:s)a[c-'a']++;
        for(auto c:t)a[c-'a']--;
        for(auto e:a)if(e!=0) return false;
        
        return true;
    }
};