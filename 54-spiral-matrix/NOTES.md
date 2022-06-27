vector<int> nSteps{nc, nr-1};
int iDir = 0;   // index of direction.
int ir = 0, ic = -1;    // initial position
while (nSteps[iDir%2]) {
for (int i = 0; i < nSteps[iDir%2]; ++i) {
ir += dirs[iDir][0]; ic += dirs[iDir][1];
res.push_back(matrix[ir][ic]);
}
nSteps[iDir%2]--;
iDir = (iDir + 1) % 4;
}
return res;
}
​
​
// prev solution -------------------
class Solution {
public:
vector<int> spiralOrder(vector<vector<int>>& m) {
vector<int>out;
int lr=0, lc=0 , hr=m.size()-1 , hc=m[0].size()-1;
while(lr<=hr && lc<=hc){
//right
if(lr<=hr){
for(int j=lc;j<=hc;j++){
out.push_back(m[lr][j]);
} lr++;
}
//down
if(lc<=hc){
for(int i=lr; i<=hr ;i++){
out.push_back(m[i][hc]);
} hc--;