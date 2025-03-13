class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int s = 0;
        int k = 0;
        vector<int>da(n+1);

        for(int i=0;i<n ; i++){

            while( s+da[i] < nums[i]){
                if(k==queries.size()) return -1;
                if( queries[k][1] >= i ){
                    da[max(queries[k][0],i)] += queries[k][2];
                    da[queries[k][1]+1] -= queries[k][2];
                }
                k++;
            }

            s+= da[i] ;
        }

        return k;
    }
};