class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //dfs or bfs ? 
        // dfs first 
        
        int n =graph.size();
        vector<bool>visited(16,0);
        
        helper(graph,visited,n-1,0,{});
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
        vector<int>v = m[curr];
        for(auto nei : v){
            if(!visited[nei]) helper(m,visited,dest,nei,path);    
        }
        
        visited[curr]=0;
        path.pop_back();
    }
};