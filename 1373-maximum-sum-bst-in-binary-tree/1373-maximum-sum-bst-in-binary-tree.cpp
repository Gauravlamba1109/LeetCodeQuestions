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
struct cus{
        bool bst;
        int ma;
        int mi;
        int sum;
    
    cus(){
        bst=1;
         ma=INT_MIN;
         mi=INT_MAX;
         sum=0;
    }
};

class Solution {
public:
    int res;
    int maxSumBST(TreeNode* root) {
        res = 0;
        helper(root);
        return res;
    }
    
    
    cus* helper(TreeNode* root){
        if(root==NULL){
            cus* c = new cus();
            return c;
        }
        
        cus* ans = new cus();
        cus* l = helper(root->left);
        cus* r = helper(root->right);
        
            
        if(l->bst==1 && r->bst==1 && (root->val > l->ma) && (root->val < r->mi) ){
            ans->bst = 1;
            ans->sum = l->sum+r->sum+ root->val;
            ans->mi = min(root->val,l->mi);
            ans->ma = max(root->val,r->ma);
        }else{
            ans->bst = 0;
            ans->sum = max(l->sum, r->sum);
        }
        res = max(ans->sum,res); 
        return ans;
    }
};