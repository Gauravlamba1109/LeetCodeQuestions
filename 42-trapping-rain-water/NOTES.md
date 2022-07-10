class Solution {
public:
int trap(vector<int>& height) {
// the block at i can have
// min( max h at left  ,  max h at right ) - curr h
// water abouve it
int ans=0;
vector<int>right;
right.push_back(height[height.size()-1]);
for(int i=height.size()-2; i>=0 ; i--){
right.push_back(max(height[i],right[right.size()-1]));
}
reverse(right.begin(),right.end());
int maxleft=height[0];
for(int i=1;i<height.size()-1;i++){
int t =     min(maxleft,right[i]) - height[i];
ans += (t<0)?0:t ;
maxleft = max(maxleft,height[i]);
}
return ans;
}
};