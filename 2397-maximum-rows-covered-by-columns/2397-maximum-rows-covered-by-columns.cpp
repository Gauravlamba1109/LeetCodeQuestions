// select numSelect columns from mat and count the max covered rows 
// then backtarck and select different combin and repeat

class Solution {
public:
    int ans;
    int maximumRows(vector<vector<int>>& mat, int numSelect) {
        ans=0;
        int n = mat.size(), m = mat[0].size() ;
        vector<int>chos(m,0);
        helper(mat,chos,0,n,m,numSelect);
        return ans;
    }
    
    // O(2^m) * O(n*m) = nm*(2^m)
    void helper(vector<vector<int>>& mat,vector<int>&chose, int c, int n ,int m, int cols){
        if(cols == 0){
            int cntRows = calcRow(mat,chose,n,m);
            ans = max(ans,cntRows);
            return ;
        }
        
        if(c>=m) return ;
        
        helper(mat,chose,c+1,n,m,cols);
        chose[c]=1;
        helper(mat,chose,c+1,n,m,cols-1);
        chose[c]=0;
    }
    
    // covered count o(n*m)
    int calcRow(vector<vector<int>>& mat,vector<int>&chose, int n ,int m){
        int cnt = 0;
        for(int i=0;i<n;i++){
            bool ok = 1;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && chose[j]==0){ // if its set and still not choosen 
                    ok = 0;
                    break;
                }
            }
            if(ok)cnt++;
        }
        return cnt;
    }
};