class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int cnt=1;
        vector<vector<int>>ans(n,vector<int>(n,0));
        // there are n+1/2 layers present 
        for(int i=0; i<(n+1)/2 ; i++){
            // left to right end 
            for(int j=i; j< n-i ; j++){
                ans[i][j]=cnt++;
            }
            // top+1 to bottom 
            for(int j=i+1; j< n-i ; j++){
                ans[j][n-i-1]=cnt++;
            }
            // bottom+1 to left bottom 
            for(int j= n-i-2 ; j>=i ; j--){
                ans[n-i-1][j]=cnt++;
            }
            // left bottom -1 to left top+1
            for(int j= n-i-2 ; j>i ; j-- ){
                ans[j][i]=cnt++;
            }
        }
        
        return ans;
    }
};