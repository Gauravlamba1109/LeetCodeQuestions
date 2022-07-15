class Solution {
public:
    set<int>seen;
    
    int find(int n,vector<int>&par){
        while(par[n]!=n){
            par[n] = par[par[n]];
            n = par[n];
        } 
        return n;
    }
    bool unio(int an,int bn,vector<int>&rank,vector<int>&par){
        int a = find(an,par);
        int b = find(bn,par);
        
        if(a==b) return false;
        else{
            if(rank[a]==rank[b]){
                par[b] = a;
                rank[a]+=rank[b];
            }else{
                if(rank[a]>rank[b]){ par[b]=a; rank[a]+=rank[b]; }
                else { par[a]=b; rank[b]+=rank[a]; }
            }
        }
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>par(1001);
        for(int i=0;i<1001;i++)par[i]=i;
        vector<int>rank(1001,1);  // basically the size of each graph starting from rank[i] as parent
        vector<int>ans={};
        for(auto e : edges){
            bool t = unio(e[0],e[1],rank,par);
            if(!t)ans = e ;
        }
        return ans;
        
        
        
        
        /*
        
        vector<int>parent(1001,0);
        for(int i=0 ; i <1001 ; i++){
            parent[i]=i;
        }
        vector<int>res;
        
        for(auto v : edges ){
            int n1 = v[0], n2 = v[1];
            while(n1 != parent[n1]) n1 = parent[n1];
            while(n2 != parent[n2]) n2 = parent[n2];
            if( n1 == n2 )
                res = v;
            else
                parent[n1] = n2;
        }
        return res;
        
        
        */
    }
};