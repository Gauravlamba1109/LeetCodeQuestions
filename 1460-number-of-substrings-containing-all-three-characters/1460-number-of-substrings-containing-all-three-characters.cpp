class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int conso=0;
        int l=0,r=0;
        unordered_map<char,int>vow;
        while(r<s.size()){
            if(s[r]=='a' || s[r]=='b' || s[r]=='c'){
                vow[s[r]]++;
            }else conso++;

            while(vow.size()==3){
                ans+=s.size()-r;
                if(s[l]=='a' || s[l]=='b' || s[l]=='c'){
                    vow[s[l]]--;
                    if(vow[s[l]]==0)vow.erase(s[l]);
                }else conso--;
                l++;
            }
            r++;
        }

        return ans;
    }
};