class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix[0].size(),vector<int>(matrix[0].size(),-1));
        for( int i=0; i<matrix.size(); i++)
            dp[matrix.size()-1][i]=matrix[matrix.size()-1][i];

        for(int i=matrix.size()-2;i>=0;i--){
            for(int j=matrix[i].size()-1;j>=0;j--){
                int down = dp[i+1][j];
                int dr = j+1<matrix.size()? dp[i+1][j+1] : 1e9;
                int dl = j-1>=0 ?dp[i+1][j-1] : 1e9;
                dp[i][j]= matrix[i][j]+ min({down,dr,dl});
            }
        }

        int ans = INT_MAX;

        // for( auto a : dp){
        //     for(auto e : a ) cout<<e<<" ";
        //     cout<<endl;
        // }
        for( auto a : dp[0] ){
            ans = min(ans,a);
        }
        return ans;
    }
};