class Solution {
public:
    int dp[1001][1001]={};
    int kInversePairs(int n, int k) {
        // if i fix starting as 
        // 1 ; i expect to find k pairs from n-1 elements after it 
        // 2 ; i expect k-1 pairs from n-1 eles as 2,1 is 1 inverse pairs pr 
        // 3 , k-2 pairs as 3,2 3,1 are 2 inverse pairs 
        
        // recu will be like 
        // k==0 kip=1
        // n==0 kip=0
        // if(k==0) return 1 ; if(n==0) return 0;
        // for(int i=1;i<=n;i++){
        //      ans+=kip(n-1,k-i);
        // }
        
        int dp[1001][1001]={1};
        
        for(int N=1;N<=n;N++){
            for(int K=0;K<=k;K++){
                for(int i=0;i<=min(N-1,K);i++) 
                    dp[N][K]=(dp[N][K]+dp[N-1][K-i])%1000000007;
            }
        }
        return dp[n][k];
    }
};