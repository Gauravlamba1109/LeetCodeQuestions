class Solution {
public:
TreeNode* sortedArrayToBST(vector<int>& nums) {
return helper(nums,0,nums.size()-1);
}
TreeNode* helper(vector<int>&nums , int i, int j){
if(i>j)return NULL;
if(i==j){
return new TreeNode(nums[i]);
}
int mid=i+(j-i)/2;
TreeNode* head=new TreeNode(nums[mid]);
head->left=helper(nums,i,mid-1);
head->right=helper(nums,mid+1,j);
return head;
}
};