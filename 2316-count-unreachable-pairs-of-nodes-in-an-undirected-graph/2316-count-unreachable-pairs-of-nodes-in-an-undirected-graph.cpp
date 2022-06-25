class Solution {
public:
    int findpar(int u , vector<int>& par){
        if(u==par[u]) return u;
        return par[u]=findpar(par[u],par);
    }
    
    void unionn(int u, int v,vector<int>& par ,vector<int>& rank){
        u= findpar(u,par);
        v= findpar(v,par);
        
        if(rank[u]<rank[v]) par[u]=v;
        else if(rank[u]>rank[v]) par[v]=u;
        else {
            par[v]=u;
            rank[u]++;
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        if(edges.size()==0){
            n = n - 1;
            if(n%2==0){
                return (long long)(n+1)*(n/2); 
            }else 
                return (long long)((n+1)/2)*n ; 
        }
        
        long long cnt=0;
        vector<int>parent(n,-1);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++)
            parent[i]=i;
    
        for(auto v : edges){
            if(parent[v[0]]==parent[v[1]])continue;
            unionn(v[0],v[1],parent,rank);
        }
        
        for(int i=0;i<n;i++){
            parent[i]= findpar(i,parent);
        }
        
        unordered_map<int,long long>p;
        for(int i=0;i<n;i++){
            p[parent[i]]++;
        }
        
        vector<long long>v;
        for(auto e : p){
            v.push_back((long long)e.second);
        }
        
      
        long long sum = accumulate(v.begin(),v.end(),0);
        for(int i=0;i<v.size();i++){
            sum=(long long)sum-(long long)v[i];
            cnt+= (long long)(v[i]*(long long)(sum));
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==j || parent[i]==parent[j] || findpar(i,parent)==findpar(j,parent))continue;
        //         else cnt=cnt+1;
        //         // return cnt/2;
        //     }
        // }
        
        return cnt;
    }
};