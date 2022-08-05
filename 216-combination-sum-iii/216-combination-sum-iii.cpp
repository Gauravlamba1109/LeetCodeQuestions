class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>sofar;
        solve(k,n,sofar);
        return ans;
    }
    
    void solve(int k,int n,vector<int>&sofar){
        if(n<0) return ;
        if(sofar.size()==k && n!=0) return ;
        if(n==0 ){
            if(sofar.size()!=k) return ;
            ans.push_back(sofar);
            return ;
        }
        int start;
        if(sofar.size()==0)start=1;
        else start= sofar.back()+1;
        
        for(int s=start; s<=min(n,9); s++){
            sofar.push_back(s);
            solve(k,n-s, sofar);
            sofar.pop_back();
        }
        
        return ;
    }
};