class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n=s.size();
        int ans=0;
        int left=0,right=n-1;
        while(left<right){
            // do stuff 
            int l=left,r=right;
            while(s[l]!=s[r])r--;    // find ele equal to s[l] after l
            if(l==r){                // if not found then we have 
                swap(s[l],s[l+1]);   // no choice but to move l to middle 
                ans++; continue;
            }else{                   // if found then we need this ele at right
                while(r<right){
                    swap(s[r],s[r+1]);
                    r++;             // keep swaping until we reach rt
                    ans++;
                }
            }
            left++, right--;
        }
        return ans;
    }
};