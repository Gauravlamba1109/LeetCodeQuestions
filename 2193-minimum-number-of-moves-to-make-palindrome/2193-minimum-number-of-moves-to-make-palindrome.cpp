class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n=s.size();
        int ans=0;
//         int left=0,right=n-1;
//         while(left<right){
//             // do stuff 
//             int l=left,r=right;
//             while(s[l]!=s[r])r--;    // find ele equal to s[l] after l
//             if(l==r){                // if not found then we have 
//                 swap(s[l],s[l+1]);   // no choice but to move l to middle 
//                 ans++; continue;
//             }else{                   // if found then we need this ele at right
//                 while(r<right){
//                     swap(s[r],s[r+1]);
//                     r++;             // keep swaping until we reach rt
//                     ans++;
//                 }
//             }
//             left++, right--;
//         }
        
        // greedy solution 

        while(s.size()){
            int i= s.find(s.back()); // find the companion of lastonne 
            if(i==(s.size()-1)){       // if its not pr; then this ele should
                ans+=i/2;            // be present at the middle of string
            }else{
                ans+=i;              // if present we need it at start of string
                s=s.erase(i,1);       // to bring it to start we front we need i swaps
            }                        // after that we can chop the starting ele 
            s.pop_back();            // and ending ele as we no longer need them 
        }
        return ans;
    }
};



