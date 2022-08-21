int ans=0;
void inorder(TreeNode* root,int& k){
// iterative using stack
int n=0;
stack<TreeNode*>st;
TreeNode* curr = root;
while(curr){
while(curr){ //move to extreme left
st.push(curr);
curr=curr->left;
}
curr = st.top(); st.pop();
n+=1;
if(n==k){ans= curr->val; return ;}
curr = curr->right;
}
// if(root)
// {
//     inorder(root->left,k);
//     if(--k==0) {ans=root->val; }
//     // arr.push_back(root->val);
//     inorder(root->right,k);
// }
// return;
}
int kthSmallest(TreeNode* root, int k) {
// vector<int> a;
inorder(root,k);
return ans;
}