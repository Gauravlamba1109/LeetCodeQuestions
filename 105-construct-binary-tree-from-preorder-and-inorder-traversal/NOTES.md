//         // cout<<endl;
//         // for(auto e:npr)cout<<e<<" ";
//         // cout<<endl;
//         root->left=buildTree(npl,nil);
//         root->right=buildTree(npr,nir);
//         return root;
// return helper(preorder,inorder,0,inorder.size()-1);
}
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
};
​