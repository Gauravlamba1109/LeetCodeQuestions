class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        long long res = 0, curr = 0;

        // Window starts at coins[i][0]
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && coins[j][1] <= coins[i][0] + k - 1) {
                curr += 1LL * (coins[j][1] - coins[j][0] + 1) * coins[j][2];
                ++j;
            }

            if (j < n) {
                long long part = 1LL *
                    max(0, coins[i][0] + k - coins[j][0]) * coins[j][2];
                res = max(res, curr + part);
            }

            curr -= 1LL * (coins[i][1] - coins[i][0] + 1) * coins[i][2];
        }

        // Window ends at coins[i][1]
        curr = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            curr += 1LL * (coins[i][1] - coins[i][0] + 1) * coins[i][2];

            while (coins[j][1] < coins[i][1] - k + 1) {
                curr -= 1LL * (coins[j][1] - coins[j][0] + 1) * coins[j][2];
                ++j;
            }

            long long outside = 1LL *
                max(0, coins[i][1] - k - coins[j][0] + 1) * coins[j][2];

            res = max(res, curr - outside);
        }

        return res;
    }
};