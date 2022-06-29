class Solution {
public:
int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
int ans=0,mini,maxi;
vector<vector<int>> sign={{1,1,1},{-1,1,1},{1,-1,1},{1,1,-1},{1,-1,-1},{-1,-1,1},{-1,1,-1},{-1,-1,-1}};
for(auto x : sign){
mini=INT_MAX,maxi=INT_MIN;
for(int i=0;i<arr1.size();i++){
mini=min(mini,x[0]*arr1[i]+x[1]*arr2[i]+x[2]*i);
maxi=max(maxi,x[0]*arr1[i]+x[1]*arr2[i]+x[2]*i);
}
ans=max(ans,maxi-mini);
}
return ans;
}
};