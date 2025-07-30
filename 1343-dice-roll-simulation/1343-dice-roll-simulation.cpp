class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(6, vector<int>(16, -1)));
        return dfs(n,rollMax, -1, 0,dp);
    }
    int mod = int(1e9+7);
    
    int dfs(int n, vector<int>&rollMax, int last, int freqOfLast, vector<vector<vector<int>>>& dp ){
        if(n==0){
            return 1;
        }

        if( last>-1 ){
            if(dp[n][last][freqOfLast]!=-1) return dp[n][last][freqOfLast];
        }

        int outp = 0;
        for(int i=0;i<6;i++){
            // change last if freq of last is exhaused
            // choose last if not 
            if( last == i && rollMax[last]>freqOfLast){
                outp = (outp+dfs(n-1, rollMax, last, freqOfLast+1,dp ))%mod ;
            } else if (last != i ){
                outp = (outp+dfs(n-1, rollMax, i, 1,dp))%mod;
            }
        }
        if(last>-1) dp[n][last][freqOfLast]=outp;
        return outp;
    }
};