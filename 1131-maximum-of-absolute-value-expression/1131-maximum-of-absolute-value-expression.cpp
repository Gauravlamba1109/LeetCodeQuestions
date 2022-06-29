class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        vector<vector<int>> sign={{1,1,1},{-1,1,1},{1,-1,1},{1,1,-1},{1,-1,-1},{-1,-1,1},{-1,1,-1},{-1,-1,-1}};
        int ans=0;
        for(auto s : sign){
            int maxi = INT_MIN;
            int mini = INT_MAX;
            for(int i=0;i<arr1.size();i++){
                maxi = max(maxi, s[0]*arr1[i] + s[1]*arr2[i] + s[2]*i);
                mini = min(mini, s[0]*arr1[i] + s[1]*arr2[i] + s[2]*i); 
            }
            ans = max(ans,maxi-mini);
        }   
        return ans;
    }
};

// abs(a-b) = max( a-b , b-a )
    