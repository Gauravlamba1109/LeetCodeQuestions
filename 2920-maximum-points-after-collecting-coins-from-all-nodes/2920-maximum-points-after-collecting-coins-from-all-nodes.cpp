class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        vector<vector<int>> adj(edges.size()+1);
        vector<vector<int>>dp(edges.size()+1,vector<int>(16,-1));

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        return dfs(adj,k,coins,0,0,0,dp);
    }

    int dfs(vector<vector<int>>&adj, int k, vector<int>& coins, int p, int node,int parent,vector<vector<int>>&dp ){
        if(dp[node][p]!=-1){
            return dp[node][p];
        }
        int w1 = (coins[node]>>p)-k;
        int w2 = (coins[node]>>p)/2;
        if(p+1==15) return dp[node][p]=w1;

        for(auto v : adj[node]){
            if(v!=parent){
                w1+= dfs(adj,k,coins,p,v,node,dp);
                w2+= dfs(adj,k,coins,p+1,v,node,dp);    
            }
        }

        return dp[node][p]= max(w1,w2);
    }
};