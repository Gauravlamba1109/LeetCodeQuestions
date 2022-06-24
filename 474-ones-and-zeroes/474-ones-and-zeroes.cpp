class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int siz = strs.size();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int k=0 ; k<siz ; k++){
            int ones = count(strs[k].begin(),strs[k].end(),'1');
            int zeros = strs[k].size()-ones;
            
            for(int i=m ; i>=zeros ; i--){
                for(int j=n ; j>=ones ; j--){
                    dp[i][j]= max(dp[i][j],dp[i-zeros][j-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};