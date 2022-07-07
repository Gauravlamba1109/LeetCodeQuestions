#define pp pair<int, char> 
#define node pair<int, string> 

class Solution {
    unordered_map<int, vector<pp>> graph;
    unordered_map<int, bool> visited;
    string result;
    
    void buildGraph(TreeNode* root, TreeNode* parent) {
        if(root == NULL)
            return;
        
        if(parent)
            graph[root->val].push_back({parent->val, 'U'});
        
        if(root->left)
            graph[root->val].push_back({root->left->val, 'L'});
        
        if(root->right)
            graph[root->val].push_back({root->right->val, 'R'});
        
        buildGraph(root->left, root);
        buildGraph(root->right, root);
    }
    
    bool dfs(int source, int destination, string &currPath) {
        visited[source] = true;
        
        if(source == destination)
            return true;
            
        for(auto dest: graph[source]) {
            if(visited[dest.first] == false) {
                visited[dest.first] = true;
                
                currPath.push_back(dest.second);
                if(dfs(dest.first, destination, currPath))
                    return true;
                
                currPath.pop_back();
            }
        }
        
        return false;
    }
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        buildGraph(root, NULL);
        
        string path;
        dfs(startValue, destValue, path);
        
        return path;
    }
};