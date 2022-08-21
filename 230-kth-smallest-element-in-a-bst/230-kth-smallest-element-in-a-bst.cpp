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
    int kthSmallest(TreeNode* root, int k) {
        int pos=0;
        int t = helper(root,k,pos);
        return t;
    }
    
    int helper(TreeNode* root, int k,int& m){
        if(root==NULL) return INT_MIN;
        
        int ans = helper(root->left,k,m);
        if(ans!=INT_MIN) return ans;
        
        m++;
        if(k==m){
            return root->val;
        }
        
        return helper(root->right,k,m);
        
    }
};