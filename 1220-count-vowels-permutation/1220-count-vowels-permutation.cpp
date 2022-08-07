class Solution {
public:
    #define inf 1000000007
    int a=0,e=1,i=2,o=3,u=4;
    long long dp[5][20001]={-1};
    int countVowelPermutation(int n) {
        for(int i=0;i<5;i++){
            memset(dp[i],-1, sizeof(dp[i][0]) * 20001);
        }
        dp[0][1]=1;
        dp[1][1]=2;
        dp[2][1]=4;
        dp[3][1]=2;
        dp[4][1]=1;
        
        return solve(-1,n);
    }
    
    long long solve(int prev, int n){
        if(n==1){
            if(prev==-1){
                return 5;
            }else{
                return dp[prev][n];
            }
        }
        
        if(prev>=0 && dp[prev][n]!=-1) return dp[prev][n];
        
        if(prev==-1){long long l =  (long long)(solve(0,n-1)+solve(1,n-1)+solve(2,n-1)+solve(3,n-1)+solve(4,n-1))%(1000000007); return l;}  
        else if(prev==0) return dp[prev][n]=(solve(1,n-1))%1000000007;
        else if(prev==1) return dp[prev][n]=(solve(0,n-1)+solve(2,n-1))%1000000007;
        else if(prev==2) return dp[prev][n]=(solve(0,n-1)+solve(1,n-1)+solve(3,n-1)+solve(4,n-1))%1000000007;
        else if(prev==3) return dp[prev][n]=(solve(4,n-1)+solve(2,n-1))%1000000007;
        else if(prev==4) return dp[prev][n]=(solve(0,n-1))%1000000007;

        return 0;
    }
};