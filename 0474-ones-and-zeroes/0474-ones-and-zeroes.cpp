class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(
            101,
            vector<vector<int>>(101, vector<int>(strs.size() + 1, -1))
        );

        return sol(strs, m, n, 0, 0, dp);
    }

    int sol(vector<string>& strs, int m, int n, int i, int siz,
            vector<vector<vector<int>>>& dp) {
        if (i == strs.size()) return 0;

        if (dp[m][n][i] != -1) return dp[m][n][i]; // changed

        int z = count(strs[i].begin(), strs[i].end(), '0');
        int o = count(strs[i].begin(), strs[i].end(), '1');

        int a = (m-z>=0 &  n-o>=0)?1+sol(strs, m - z, n - o, i + 1, siz + 1, dp):0;
        int b = sol(strs, m, n, i + 1, siz, dp);


        dp[m][n][i] = max(a, b); // changed

        return dp[m][n][i]; // changed
    }
};