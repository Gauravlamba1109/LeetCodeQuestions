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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int ps , int pe , int is ,int ie){
        if(is>ie) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        
        // abs position 
        int it = find(inorder.begin()+is,inorder.begin()+ie,preorder[ps])-(inorder.begin());
        
        root->left = helper(preorder,inorder,ps+1,ps+(it-is),is,it-1);
        root->right= helper(preorder,inorder,ps+((it-is)+1),pe,it+1,ie);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder root left right
        // inorder left root right 
       
        int ps = 0;
        int is = 0;
        int pe = preorder.size()-1;
        int ie = inorder.size()-1;
        return helper(preorder,inorder, ps,pe, is, ie);
        
        
        
        
        
        
        
        ////// 06/01/2022
        
//         if(preorder.size()==0 || inorder.size()==0) return NULL;
        
//         TreeNode* root = new TreeNode(preorder[0]);
//         int mid = find(inorder.begin(),inorder.end(),root->val)-inorder.begin();
        
//         // cut preorder in => left= mid ele from starting , right = inordersize-mid-1 elements from starting+left-ele 
//         auto is = inorder.begin();
//         auto ie = inorder.end();
//         auto ps = preorder.begin();
//         auto pe = preorder.end();
//         vector<int>nil(is,is+mid);
//         vector<int>nir(is+mid+1,ie);
        
//         vector<int>npl(ps+1,ps+1+nil.size());
//         vector<int>npr(ps+1+npl.size(),pe);
//         // for(auto e:nil)cout<<e<<" ";
//         // cout<<endl;
//         // for(auto e:nir)cout<<e<<" ";
//         // cout<<endl;
//         // for(auto e:npl)cout<<e<<" ";
//         // cout<<endl;
//         // for(auto e:npr)cout<<e<<" ";
//         // cout<<endl;
        
//         root->left=buildTree(npl,nil);
//         root->right=buildTree(npr,nir);
        
//         return root;
        
        
        
        // return helper(preorder,inorder,0,inorder.size()-1);
    }
    
    /*
    int cnt=0;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int st,int en){
        if(st<0 ||en>=inorder.size())return NULL;
        if(st>en)return NULL;
        TreeNode* head=new TreeNode(preorder[cnt]);
        cnt++;
        
        
        int t=st;
        while(t<=en){
            if(head->val==inorder[t]) break;
            t++;
        }
        
        head->left=helper(preorder,inorder,st,t-1);
        head->right=helper(preorder,inorder,t+1,en);
        
        return head;
    }
    */
};