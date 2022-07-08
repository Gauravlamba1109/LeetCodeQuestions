class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<vector<int>>tbl(stones.size(),vector<int>(stones.size()*100,-1));
        int n = stones.size()-1; 
        return rec(stones,n,0,tbl);
    }
    
    int rec(vector<int>&stones,int n ,int wei, vector<vector<int>>&tbl){
        if(n==0) return abs(wei-stones[n]);
        if(tbl[n][wei]!=-1) return tbl[n][wei];
        
        return tbl[n][wei] =
        min( 
            rec(stones,n-1,abs(wei-stones[n]),tbl),
            rec(stones,n-1,abs(wei+stones[n]),tbl)
        );
    }
};