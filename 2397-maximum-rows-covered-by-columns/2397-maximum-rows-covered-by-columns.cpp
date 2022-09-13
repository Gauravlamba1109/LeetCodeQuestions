
class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int numSelect) {
        int n = mat.size();
        int m = mat[0].size();
        
        int maxx = 1<<m; // max possible options 
            
        int ans = 0;
        for(int mask = 0; mask<maxx ; ++mask){
            if(__builtin_popcount(mask)!=numSelect) continue;
            
            int cnt = 0;
            for(int i=0;i<n;++i){
                int j=0;
                for(j=0;j<m;++j){
                    // if not set and not pre in mask break early  
                    if(((mask>>j)&1 )== 0  && mat[i][j]==1) break;
                }
                if(j==m)cnt++; // we didnt find any set and not pre in mask 
            }
            
            ans = max(ans,cnt);
        }
        
        return ans;
    }
    
    // __builtin_popcount
   int countBits(int bits) {
        int ret = 0;
        for (int i = 1; i <= (1 << 12); i <<= 1) {
            if (bits & i)
                ++ret;
        }
        return ret;
    }
    
    
    /*
    
    // select numSelect columns from mat and count the max covered rows 
    // then backtarck and select different combin and repeat
    
    easy solution o(nm*(2^m)) tc ; sc O(m*2^m)
    
    
    int ans;
    int maximumRows(vector<vector<int>>& mat, int numSelect) {
        ans=0;
        int n = mat.size(), m = mat[0].size() ;
        int chos = 0;
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
    
    */
};