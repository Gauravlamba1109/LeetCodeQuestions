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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,bool>m;
        bool ans = helper(root,k,m);
        return ans;
    }
    
    bool helper(TreeNode* root, int k , unordered_map<int,bool>&m){
        if(root==NULL) return false;
        if(m.find(k-(root->val))!=m.end()) return true;
        m[root->val]=1;
        bool l = helper(root->left,k,m);
        bool r = helper(root->right,k,m);
        
        return l||r;
    }
};