// need to build BST in this case. Thus saving time.
// If array is in non-decreasing fashion,  we will return a vector of 0's
// because in this case, no element in the right of the current element will the greater than it.
while(j<n && nums[j-1]<=nums[j]) j++;
if(j==n) return vect;
j=n-2;
// Similarly we also check if input array is in non-increasing fashion, in this case too we dont need BST
// If this is the case, then appropriate values is stored in "vect" array.
while(j>-1 && nums[j]>=nums[j+1]){
if(nums[j]>nums[j+1])
vect[j]=n-j-1;
if(nums[j]==nums[j+1]) vect[j]=vect[j+1];
j--;
}
// if array is in non-increasing fashion , then return "vect".
if(j==-1) return vect;
//  If input array is just random, then the last element is made as root of BST.
struct Node *root = new Node(nums[n-1]);
// We will keep inserting elements into BST from the end of the input array.
// And as discussed above, "insert" function will return the count of elements lesser
// than the current variable.
for(int i=n-2;i>-1;i--)
vect[i]=insert(root,nums[i]);
// Answer returned.
return vect;