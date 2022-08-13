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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    
    TreeNode* helper(vector<int>& preorder,int ps, int pe, vector<int>& inorder, int is,int ie){
        if(ps>pe || is>ie) return NULL;
        
        TreeNode* root = new TreeNode(preorder[ps]);
        
        int it = find(inorder.begin(),inorder.end(),preorder[ps])-inorder.begin();
        int noleft = it-is;
        
        root->left = helper(preorder,ps+1,ps+noleft,inorder,is,is+noleft);
        root->right= helper(preorder,ps+noleft+1,pe,inorder,is+noleft+1,ie);
        
        return root;
    }
};