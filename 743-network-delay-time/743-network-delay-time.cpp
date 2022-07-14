class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto v : times){
            adj[v[0]].push_back({v[1],v[2]});
        }
        
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        vector<bool>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> >q;
        q.push({0,k});
        
        int ans= 0;
        while(q.size()){
            int distill = q.top().first;
            int node = q.top().second;
            vis[node]=1;
            q.pop();
            
            for(auto it : adj[node]){
                int to = it.first;
                int wt = it.second;
                if(dist[node] + wt < dist[to]){
                    dist[to]= dist[node]+wt;
                    q.push({dist[to],to});
                }
            }
        }
        ans= *max_element(dist.begin()+1,dist.end());
        return ans==INT_MAX?-1:ans;
    }
};