class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>dp;
        dp.push_back({1});
        // dp[i][j]= dp[i-1][j-1]+dp[i-1][j]
        
        for(int i=1;i<numRows;i++){
            vector<int>v;
            int s = dp.back().size();
            for(int j=0;j<=i;j++){
                int t = ((j<s)?dp[i-1][j]:0)+((j-1>=0)?dp[i-1][j-1]:0);
                v.push_back(t);
            }
            dp.push_back( v );
        }
        
        return dp;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         int dp[numRows+1][numRows+1];
//         memset(dp,0,sizeof dp);
//         dp[1][1]=1;
       
//         vector<vector<int>> ans;
//          ans.push_back({1});
//         for(int i=2;i <numRows+1;i++){
//             vector<int>v;
//             for(int j=1;j <i+1; j++){
//                 dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
//                 v.push_back(dp[i][j]);
//             }
//             ans.push_back(v);
//         }
//         return ans;
    }
};