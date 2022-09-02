/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        // level order using bfs 
        
        queue<TreeNode*>q;
        q.push(root);
        vector<double>ans;
        
        while(q.size()){
            int s = q.size();
            double t = 0;
            for(int i=0;i<s;i++){
                TreeNode* node = q.front(); q.pop();
                t += node->val ;
                if(node->left) q.push(node->left);
                if(node->right)q.push(node->right);
            }
            t/=s;
            ans.push_back(t);
        }
        
        return ans;
    }
};