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
    int ans=0;
    int longestUnivaluePath(TreeNode* root) {
        helper(root); 
        return ans;
    }
    
    int helper(TreeNode* root){
        if(root==NULL) return 0 ;
        
        int l = helper(root->left);
        int r = helper(root->right);
        
        int aleft=0,aright=0;
        
        if(root->left && root->left->val==root->val){
            aleft=l+1;
        } 
        if(root->right && root->right->val==root->val){
            aright=r+1;
        }
        ans = max(ans,aleft+aright);
        return max(aleft,aright);
    }
};