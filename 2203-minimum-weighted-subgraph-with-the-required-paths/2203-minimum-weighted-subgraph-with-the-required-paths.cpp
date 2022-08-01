typedef long long ll;
typedef pair<long long,int> plli;

class Solution {
public:
    const ll l = LONG_LONG_MAX;
    vector<ll> djstra(vector<vector<plli>>&g, int src, int n){
        vector<ll>dist(n, l);
        priority_queue< plli, vector<plli> , greater<plli> >q;
        q.push({0,src});
        dist[src]=0;
        
        while(!q.empty()){
            plli t = q.top(); q.pop();
            ll curr = t.first;
            int node = t.second;
            if(curr > dist[node]) continue;
            
            for(auto &chil : g[node]){
                int nei = chil.second;
                ll dis = chil.first;
                if(dist[nei]>curr+dis){
                    dist[nei]=curr+dis;
                    q.push({dist[nei],nei});
                }
            }
        }
        
        return dist;
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        //   min dist from src1 to src2 + min dist from src2 to dest
        // src1->x  src2->x  x->dest
        // rather than finding min dist from x to dest each time x changes 
        // we can calculate the min dists from dest to all nodes once 
        // and use them 
        
        vector<vector<plli>> g1(n);
        vector<vector<plli>> g2(n);

        for(auto edge:edges){
            g1[edge[0]].push_back({edge[2],edge[1]});
            g2[edge[1]].push_back({edge[2],edge[0]});
        }
        
        vector<ll>a = djstra(g1,src1,n);
        vector<ll>b = djstra(g1,src2,n);
        vector<ll>c = djstra(g2,dest,n);
        
        ll ans= l;
        for(int i=0;i<n;i++){
            if(a[i]==l || b[i]==l || c[i]==l) continue;
            ans = min(ans, a[i]+b[i]+c[i]);
        }
        
        if(ans== l) return -1;
        else return ans;
    }
};