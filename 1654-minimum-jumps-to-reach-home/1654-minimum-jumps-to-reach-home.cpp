class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        // 0->x 
        // not to step on forbidden 
        vector<vector<int>>m(7001,vector<int>(2,-1));
        map<int,bool>forb;
        for(auto ele : forbidden) 
            forb[ele]=1;
        
        int t =  dfs(forb,a,b,x,0,0,m);
        return t>1e9?-1:t;
    }
    int dfs(map<int,bool>&forb, int a, int b, int x, int curr, bool bac,vector<vector<int>>&m){
        if(curr==x) return 0;
        if(curr<0 || curr>6000 || forb.find(curr)!=forb.end() ) return 1e9;
        
        if(m[curr][bac]!=-1) return m[curr][bac];
        
        
        m[curr][bac] = 1+dfs(forb,a,b,x,curr+a,1,m);
        
        if(bac){ 
            m[curr][bac]= min(m[curr][bac],1+dfs(forb,a,b,x,curr-b,0,m));
        }
        
        return m[curr][bac];
    }
};












