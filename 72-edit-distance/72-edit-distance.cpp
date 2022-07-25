class Solution {
public:
        int dp[501][501];
    
    int helper(string a,string b,int i,int j){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]) return dp[i][j];
        if(a[i]==b[j]) return dp[i][j]=helper(a,b,i-1,j-1);
        else{
            return dp[i][j]= min({ helper(a,b,i-1,j), helper(a,b,i-1,j-1), helper(a,b,i,j-1) })+1;
        }
        return 1e9;
    }
    
    int minDistance(string word1, string word2) {
        return helper(word1,word2,word1.size()-1,word2.size()-1);
        
        
        
        
        
        
        
        
        
        
        
        
        
        //         // naive recursive 
//         int n1 = word1.size();
//         int n2 = word2.size();
//         if(n1==0) return n2;
//         if(n2==0) return n1;
//         return helper(word1,word2,n1,n2);
//     }
    
//     int helper(string a, string b , int n1 , int n2){
// //         if(n1==0) return n2;
// //         if(n2==0) return n1;
        
// //         if(a[n1-1]==b[n2-1]) return helper(a,b,n1-1,n2-1);
        
// //         return 1 + min( helper(a,b,n1-1,n2),min(helper(a,b,n1-1,n2-1),helper(a,b,n1,n2-1)));
        
        
        
//         vector<vector<int>>dp(n1+1,vector<int>(n2+1,INT_MAX));
//         for(int i=0;i<=n1;i++) dp[i][0]=i;
//         for(int i=0;i<=n2;i++) dp[0][i]=i;

//         dp[0][0]=0;
//         for(int i=1;i<=n1;i++){
//             for(int j=1;j<=n2;j++){
//                 if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
//                 else 
//                     dp[i][j] = 1+ min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
//             }
//         }
//         return dp[n1][n2];
        
    }
};


// horsu
// ros