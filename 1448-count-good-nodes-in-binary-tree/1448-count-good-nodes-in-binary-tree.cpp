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
    int cnt=0;
    int goodNodes(TreeNode* root) {
        // dfs to leaf with a max value 
        if(!root) return 0;
        int maxi = INT_MIN;
        helper(root,maxi);
        return cnt ;
    }
    
    void helper(TreeNode* root, int maxi){
        if(root==NULL) return ;
        else{
            if(root->val>=maxi)cnt++;
            maxi = max(maxi,root->val);
            helper(root->left,maxi);
            helper(root->right,maxi);
        }
        return ;
    }
};