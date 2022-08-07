class Solution {
public:
    int countVowelPermutation(int n) {
        int a=0,e=1,i=2,o=3,u=4;
        
        vector<int>dp(5,1); // with n=1;
        
        int mod = 1000000007;
        int ans=0;
        if(n==1) return 5;
        if(n==0) return 0;
        
        for( int j=2;j<=n ; j++){
            int z= (int)((dp[e]+dp[i])%1000000007+dp[u])%1000000007; 
            int v= (dp[a]+dp[i])%1000000007;
            int w= (dp[e]+dp[o])%1000000007; 
            int x= (dp[i])%1000000007;
            int y= (dp[i]+dp[o])%1000000007;
            
            if(j==n){
                int g = (z+v)%1000000007;
                int h = (w+x)%1000000007;
                int gh = (g+h)%1000000007;
                ans = (gh+y)%1000000007; 
                return ans;
            }
            
            dp[a]=z;
            dp[e]=v;
            dp[i]=w;
            dp[o]=x;
            dp[u]=y;

        }
        
        return ans;
    }
};