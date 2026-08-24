class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int l=0;
        int maxf = 0; // the max freq we have in the wondow 
        int maxl = 0; // max len till now 

        for(int h=0;h<s.size(); h++){
            int j = s[h]-'A';
            int i = s[l]-'A';
            
            // add the curr to window 
            freq[j]++;
            maxf = max(maxf,freq[j]);

            // remove old if i-j-maxf > k  
            // update maxl
            while(( h-l+1 - maxf ) > k){
                freq[i]--;
                l++; i++;
            } 

            maxl = max(maxl,h-l+1);
        }

        return maxl;
    }
};