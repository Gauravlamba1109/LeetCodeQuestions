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
    vector<int> rightSideView(TreeNode* root) {
        // level order's last ele // bfs 
        vector<int>r;
        if(root==NULL) return r; 
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.size()!=0){
            int s = q.size();
            for(int i=0;i<s-1;i++){
                TreeNode* t = q.front(); q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            r.push_back(q.front()->val);
            if(q.front()->left)q.push(q.front()->left);
            if(q.front()->right)q.push(q.front()->right);
            q.pop();
        }
        return r;
    }
};