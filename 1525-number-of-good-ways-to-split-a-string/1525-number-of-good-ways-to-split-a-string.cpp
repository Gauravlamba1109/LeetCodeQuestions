class Solution {
public:
    int numSplits(string s) {
        int ans=0;
        int a[27]={};
        int b[27]={};
        for(auto ch : s){
            a[ch-'a']++;
        }
        for(int i=0;i<s.size();i++){
            b[s[i]-'a']++; //add to other bag
            a[s[i]-'a']--; //remove from one bag
            int sum=0;
            for(int j=0;j<27;j++) sum+=(b[j]!=0)-(a[j]!=0);
            if(sum==0)ans++;
        }
        return ans;
    }
};