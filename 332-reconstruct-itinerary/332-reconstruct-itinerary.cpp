class Solution {
public:
    int n;
    bool dfs(map<string,vector<string>>&m, vector<string>&path, string par){
        if(path.size()==n+1) return true;           // if path leng is good we found a corr order
        if(m.find(par)==m.end()) return false;      // if the curr ele has nowhere to go 
                                                    // and len is also less than n+1 means we are stuck
        
        for(int i=0;i<m[par].size();i++){           // take dest one by one  
            string nbr = m[par][i];                 
            
            if(nbr==".")continue;                   // if the dest is already being iterated over 
            
            m[par][i]=".";                          // mark the dest 
            path.push_back(nbr);                    // add to path 
            if(dfs(m,path,nbr)) return true;    // if able to make path from here return true
            m[par][i]=nbr;                          // not able to reach end so put dest back
            path.pop_back();                        // we'll choose another ele to reach end 
        }
        
        return false;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(),tickets.end());        // sort so we can insert into m lexographically 
        
        //adj list 
        map<string,vector<string>>m;
        for(auto t : tickets){
            m[t[0]].push_back(t[1]);
        }
        
        // dfs 
        n=tickets.size();
        vector<string>path;
        path.push_back("JFK");                      // starting point 
        dfs(m,path,"JFK");                          // find end 
        
        return path;
    }
};