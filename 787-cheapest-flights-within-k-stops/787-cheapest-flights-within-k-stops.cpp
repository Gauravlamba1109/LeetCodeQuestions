class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // djstra or bfs level order 
        priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>>pq;
        
        vector<pair<int,int>>adj[n]; // adjacency list 
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        vector<int>distto(n+1,INT_MAX);
        
        
        int visited[n];
        for(int i=0;i<n;i++)visited[i]=1e9;
        
        pq.push({{0,src},0});
        
        while(!pq.empty()){
            int dist = pq.top().first.first;
            int prev = pq.top().first.second;
            int l = pq.top().second;            // curr level 
            pq.pop();
            
            if(prev==dst) return dist;          // reached dest before k nodes 
            
            if(l>k || l>=visited[prev]) continue;
            
            visited[prev] =l;
            
            for(auto it: adj[prev]){
                int nxt = it.first, nxtdist = it.second;
                
                pq.push({{dist+nxtdist,nxt},l+1});
            
            }
        }
        
        return -1;
    }
};