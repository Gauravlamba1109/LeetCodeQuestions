class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<string>> partition(string s) {
        // backtracking
        int j = s.size()-1;
        vector<string>p;
        helper(s,0,j,p);
        return ans;
    }
    
    void helper(string s, int i, int j, vector<string>&p){
        if(i==s.size()){
            ans.push_back(p);
            return ;
        }
        for(int idx = i ; idx<=j;idx++){
            if(ispalan(s.substr(i,idx-i+1))){
                p.push_back(s.substr(i,idx-i+1));
                helper(s,idx+1,j,p);
                p.pop_back();
            }
        }
    }
    
    bool ispalan(string s){
        int i= 0;
        int j= s.size()-1;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++; j--;
        }
        
        return true;
    }
};