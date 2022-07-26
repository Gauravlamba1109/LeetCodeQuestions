/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans=NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* q, TreeNode* p) {
        // iterative 
        stack<TreeNode*>stack;
        map<TreeNode*,TreeNode*>parent;
        
        parent[root]=NULL;
        stack.push(root);
        
        // until i have p or q in my map ; traverse the tree 
        while(parent.find(p)==parent.end()||parent.find(q)==parent.end()){
            TreeNode* node=stack.top();
            stack.pop();
            if(node->left){
                parent[node->left]=node;
                stack.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                stack.push(node->right);
            }
        }
        
        // now i have path of p or q inside parent ;
        vector<TreeNode*>v1;
        while(p!=NULL){
            v1.push_back(p);
            p=parent[p];
        }
        while(find(v1.begin(),v1.end(),q)==v1.end()){
            q=parent[q];
        }
        return q;
        
        
        
        // recursive solution 
        // rec(root,p,q);
        // return ans;
    }
    
    /*
    bool rec(TreeNode* root,TreeNode* p , TreeNode* q){
        if(root==NULL) return 0;
        if(root==p || root==q){
            ans = root;
            return true;
        }
        
        bool l = rec(root->left,p,q);
        bool r = rec(root->right,p,q);
        
        if(l&&r)ans = root;
        if(l||r)return l||r;
        
        return false;
    }
    */
};