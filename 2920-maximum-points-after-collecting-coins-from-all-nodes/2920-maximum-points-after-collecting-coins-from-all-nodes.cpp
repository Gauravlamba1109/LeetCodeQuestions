class Solution {
    vector<vector<int>> graph;
    vector<array<int, 15>> memo;
    vector<int>* coins;
    int fee;

    int dfs(int u, int parent, int shift) {
        int& ans = memo[u][shift];
        if (ans != INT_MIN) return ans;
        int value = (*coins)[u] >> shift;
        int take = value - fee;
        int halve = value >> 1;
        for (int v : graph[u]) if (v != parent) {
            take += dfs(v, u, shift);
            halve += dfs(v, u, min(14, shift + 1));
        }
        return ans = max(take, halve);
    }
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& values, int k) {
        int n = values.size();
        graph.assign(n, {});
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        memo.resize(n);
        for (auto& row : memo) row.fill(INT_MIN);
        coins = &values;
        fee = k;
        return dfs(0, -1, 0);
    }
};