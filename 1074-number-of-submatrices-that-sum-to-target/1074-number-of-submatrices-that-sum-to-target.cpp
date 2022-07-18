class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        // make a prefix sum of each row in matrix 
        int n=mat.size();
        int m=mat[0].size();
        
        // each row will have sum of columns of that row 
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        int ans=0;
        for(int colstart=0; colstart<m; colstart++){
            for(int colend=colstart ; colend<m ; colend++){
                unordered_map<int,int> mp;
                mp[0]=1;
                int sum=0;
                for(int row=0 ; row<n; row++){
                    sum += (mat[row][colend]-(colstart?mat[row][colstart-1] : 0));
                    if(mp.find(sum-target)!=mp.end()) ans+=mp[sum-target];
                    mp[sum]++;
                }
            }
        }
        return ans;
        
    }
};









