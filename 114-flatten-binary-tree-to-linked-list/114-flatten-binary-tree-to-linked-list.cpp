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
    void flatten(TreeNode* root) {
        // iterative morris traversal O(3n) , O(1)

        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left){
                TreeNode* pred = curr->left;
                while(pred->right){
                    pred = pred->right;
                }
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }else{
                curr = curr->right;
            }
        }
        
        // recursive O(n) , O(n)
        // if(!root) return ;
        // vector<TreeNode*>v;
        // preo(root,v);
        // for(int i=0;i<v.size()-1;i++){
        //     v[i]->left=NULL;
        //     v[i]->right=v[i+1];
        // }
    }
    
    void preo(TreeNode* root, vector<TreeNode*>&v){
        if(!root) return ;
        v.push_back(root);
        preo(root->left,v);
        preo(root->right,v);
    }
};