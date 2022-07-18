class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        // make a prefix sum of each row in matrix 
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        
        int ans=0;
        for(int colstart=0; colstart<m; colstart++){
            for(int colend=colstart ; colend<m ; colend++){
                for(int rowstart=0 ; rowstart<n; rowstart++){
                    int sum=0;
                    for(int rowend=rowstart ;rowend<n; rowend++){
                        sum += (mat[rowend][colend]-(colstart?mat[rowend][colstart-1] : 0));
                        if(sum==target){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};









