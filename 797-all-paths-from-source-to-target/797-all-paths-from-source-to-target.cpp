class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //dfs or bfs ? 
        // dfs first 
        
        int n =graph.size()-1;
        vector<bool>visited(n+1,0);
        
        helper(graph,visited,n,0,{});
        return ans;
    }
    
    vector<vector<int>>ans;
    void helper(vector<vector<int>>& m, vector<bool>&visited,int dest,int curr,vector<int>path){
        if(curr>dest) return ;
        if(curr==dest){
            path.push_back(curr);
            ans.push_back(path);
            path.pop_back();
            return ;
        }
        
        visited[curr]=1;
        path.push_back(curr);
        
        for(auto nei : m[curr])
            if(!visited[nei]) 
                helper(m,visited,dest,nei,path);    
        
        
        visited[curr]=0;
        path.pop_back();
    }
};