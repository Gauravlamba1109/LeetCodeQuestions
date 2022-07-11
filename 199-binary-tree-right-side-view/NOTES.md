//for each level of the bt push the right to ans
//         vector<int>ans;
//         if(root==NULL) return ans;
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()){
//             int size=q.size();
//             ans.push_back(q.front()->val);
//             while(size--){
//                 TreeNode* temp=q.front();
//                 q.pop();
//                 if(temp->right) q.push(temp->right);
//                 if(temp->left) q.push(temp->left);
//             }
//         }
//         return ans;
}
};