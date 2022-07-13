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
    vector<vector<int>> levelOrder(TreeNode* root, int level=1, vector<int>v={}) {
      
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int siz = q.size();
            vector<int>level;
            for(int i=0 ; i<siz ; i++){
                TreeNode* curr = q.front(); q.pop();
                level.push_back(curr->val);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            ans.push_back(level);
        }
        return ans;
        
        
        
        
        
        

        
        
        
//         if(root==NULL) return {};
//         queue<TreeNode*> q1;
        
//         vector<vector<int>> ans;
        
//         q1.push(root);
//         TreeNode* t;
//         while(!q1.empty()){
//             int size= q1.size();
//             vector<int>v1;
            
//             for(int i=0;i<size ;i++){
//                 t=q1.front();
//                 q1.pop();
//                 v1.push_back(t->val);
                
//                 if(t->left!=NULL ) q1.push(t->left);
//                 if(t->right!=NULL) q1.push(t->right);    
//             }
//             ans.push_back(v1);
//         }
//         return ans;
    }
};