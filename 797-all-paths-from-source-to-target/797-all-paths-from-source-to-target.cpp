class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //dfs or bfs ? 
        // dfs first 
        helper(graph,0,{});
        return ans;
    }
    
    vector<vector<int>>ans;
    
    void helper(vector<vector<int>>& m,int curr,vector<int>path){
        path.push_back(curr);
        
        if(curr==(m.size()-1)){
            ans.push_back(path);
            return ;
        }else{
            for(auto nei : m[curr]){
                helper(m,nei,path);    
            }
        }
        path.pop_back();
        
    }
};