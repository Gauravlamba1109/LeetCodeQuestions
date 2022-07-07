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
    TreeNode* lca(TreeNode* root , int sv , int dv){
        if(root==NULL || (root->val==sv) || (root->val==dv)) return root;
        
        TreeNode* l = lca(root->left,sv,dv);
        TreeNode* r = lca(root->right,sv,dv);

        if(l==NULL && r==NULL) return NULL;
        if(l==NULL) return r;
        if(r==NULL) return l;
        return root;
    }
    
    void dfs(TreeNode* root,int tar, string& p,string& path){
        if(root==NULL){ 
            return;
        }
        if(root->val==tar){ 
            path=p;
            return ;
        }
        
        dfs(root->left,tar,p+='L',path);
        p.pop_back();
        dfs(root->right,tar,p+='R',path);
        p.pop_back();

    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* nod = lca(root,startValue,destValue);
        
        string s1="",s2="",t="";
        dfs(nod,startValue,t,s1);t="";
        dfs(nod,destValue,t,s2);
        
        for(auto &c:s1)c='U';
        return s1+s2;
    }
};