class Solution {
public:
    vector<vector<int>>ans;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size()==0) return ans;
        sort(candidates.begin(),candidates.end());
        vector<int>path;
        solve(0,candidates,target,path);
        return ans;
    }
    
    
    void solve(int t, vector<int>&can, int target,vector<int>&path){
        if(t>can.size() || target<0){
            return ; 
        }
        if(target==0){
            // push to ans
            ans.push_back(path);
            return ; 
        }
        
        for(int i=t;i<can.size();)
        {
            if(can[i]<=target){
                path.push_back(can[i]);
                solve(i+1,can,target-can[i],path);
                path.pop_back();
            } 
            int j=i;
            while(j<can.size() && can[i]==can[j])j++;
            i=j;
            if(i>=can.size())break;
        }
    }
};