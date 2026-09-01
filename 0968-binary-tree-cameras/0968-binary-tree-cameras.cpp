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
    int dfs(TreeNode* node){
        if(!node) return 2;
        int l = dfs(node->left);
        int r = dfs(node->right);

        if(l==0 || r==0 ){
            ans++;
            return 1;
        }

        return ( l==1 || r==1 ) ? 2: 0 ;
    }
    int minCameraCover(TreeNode* root) {
        // 2 covered 
        // 0 need camera
        // 1 is camera
        int a = dfs(root);
        return a==0?ans+1:ans;

    }
};