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
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
    
    int maxi = INT_MIN;
    
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        
        int ls = max(0,solve(root->left));
        int rs = max(0,solve(root->right));
        
        maxi= max((ls+rs+root->val),maxi);
        
        return max(ls,rs)+ root->val;
    }
};