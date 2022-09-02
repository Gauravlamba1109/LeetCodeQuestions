class Solution {
public:
int ans=0;
void helper(TreeNode* root , int curr){
if(!root) return ;
if(root->val >= curr)ans++;
helper(root->left,max(curr,root->val));
helper(root->right,max(curr,root->val));
}
int goodNodes(TreeNode* root,int currmax=INT_MIN) {
// another recursive approach
helper(root,INT_MIN);
return ans;
// recursive
//         if(!root) return 0;
//         return ((root->val >= currmax)? 1: 0) + goodNodes(root->left,max(currmax,root->val))
//                     + goodNodes(root->right,max(currmax,root->val));
}
};