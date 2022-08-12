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
    bool isValidBST(TreeNode* root,TreeNode* mi=NULL,TreeNode* ma=NULL) {
        if(!root) return true;
        
        bool t = (mi && mi->val >= root->val) || (ma && ma->val <= root->val) ;
        if(t)return false;
        
        return isValidBST(root->left,mi,root)&&isValidBST(root->right,root,ma);
    }
};


/*
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isval(root,NULL,NULL);
    }
    bool isval(TreeNode* root,TreeNode* mi,TreeNode* ma){
        if(root==NULL)return true;
            if(mi && mi->val>=root->val || ma && ma->val<=root->val) return false;
        return isval(root->left,mi,root)&&isval(root->right,root,ma);
    }
};

*/