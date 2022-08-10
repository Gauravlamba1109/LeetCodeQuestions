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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)return NULL;
        if(nums.size()==1){
            TreeNode* n = new TreeNode(nums[0]);
            return n;
        }
        int mid = nums.size()/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int>a,b;
        for(int i=0;i<mid;i++)a.push_back(nums[i]);
        for(int i=(mid+1);i<nums.size();i++)b.push_back(nums[i]);

        root->left = sortedArrayToBST(a);
        root->right= sortedArrayToBST(b);
        
        return root;
    }
    
};