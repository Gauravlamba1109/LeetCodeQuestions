class Solution {
private:
    bool f(int i1, int i2, string &s, string &p, vector<vector<int>>& dp) {
        // Base case: both string and pattern fully matched
        if (i1 == s.size() && i2 == p.size()) return true;

        // If pattern is over but string is not → no match
        if (i2 == p.size()) return false;

        // If string is over, pattern must be only '*' to match
        if (i1 == s.size()) {
            for (int k = i2; k < p.size(); k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        // Return memoized result if already computed
        if (dp[i1][i2] != -1) return dp[i1][i2];

        // Case 1: Exact character match or '?'
        if (p[i2] != '?' && p[i2] != '*') {
            if (s[i1] != p[i2]) return dp[i1][i2] = false;
            return dp[i1][i2] = f(i1 + 1, i2 + 1, s, p, dp);
        }
        else if (p[i2] == '?') {
            return dp[i1][i2] = f(i1 + 1, i2 + 1, s, p, dp);
        }
        else { // Case 2: '*' can match zero or more characters
            return dp[i1][i2] = (f(i1 + 1, i2, s, p, dp) ||  // match one char
                                 f(i1, i2 + 1, s, p, dp));   // match zero char
        }
    }

public:
    bool isMatch(string s, string p) {
        // Initialize dp with -1 (uncomputed states)
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return f(0, 0, s, p, dp);
    }
};