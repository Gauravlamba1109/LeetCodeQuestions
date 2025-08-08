class Solution {
public:

    vector<int>dp;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(367);
        return dfs(days,costs,0);
    }

    int dfs(vector<int>& days, vector<int>& costs, int i){
        if( i>= days.size() ) return 0;

        if(dp[i]) return dp[i];

        int costA = costs[0] + dfs(days, costs, i+1);

        int j;
        for(j=i;j<days.size() && days[j]<days[i]+7 ;j++);
        int costB = costs[1] + dfs(days, costs, j);

        for(j=i;j<days.size() && days[j]<days[i]+30 ;j++);
        int costC = costs[2] + dfs(days, costs, j);

        dp[i] = min({costA,costB,costC}); 
        return dp[i];
    }
};