class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>sofar;
        solve(k,n,sofar,1);
        return ans;
    }
    
    void solve(int k,int n,vector<int>&sofar,int start){
        if(n<0) return ;
        
        if(sofar.size()==k){
            if(n==0 ){
                ans.push_back(sofar);
            }
            return ;
        }
        
        for(int s=start; s<=min(n,9); s++){
            sofar.push_back(s);
            solve(k,n-s, sofar,s+1);
            sofar.pop_back();
        }
        
        return ;
    }
};