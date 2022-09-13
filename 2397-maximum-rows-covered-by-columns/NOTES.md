class Solution {
private:
int ans;
void helper(vector<vector<int>>& mat, vector<int> &chose, int c, int n, int m, int cols) {
if(cols == 0) { // We choose all required columns
int cntRows = calcRow(mat, chose, n, m);
ans = max(ans, cntRows);
return;
}
if(c >= m) { // if column size is exhausted and we haven't chosen the required amount of columns
return;
}
helper(mat, chose, c + 1, n, m, cols); // not choosing this column
// choose this column
chose[c] = 1; // mark this column
helper(mat, chose, c + 1, n, m, cols - 1);
chose[c] = 0; // unmark this column
}
int calcRow(vector<vector<int>>& mat, vector<int> &chose, int n, int m) {
int cnt = 0;
for(int i = 0; i < n; i++) {
bool ok = 1;
for(int j = 0; j < m; j++) {
// If this cell in the ith row contains '1' but we haven't chosen this column, thus we cannot consider this row as covered
if(mat[i][j] == 1 && chose[j] == 0) {
ok = 0;
break;
}
}
if(ok) cnt++;
}
return cnt;
}
public:
int maximumRows(vector<vector<int>>& mat, int cols) {
ans = 0;
int n = mat.size(), m = mat[0].size();
vector<int> chose(m, 0); // to track the chosen columns
helper(mat, chose, 0, n, m, cols);
return ans;
}
};