class Solution {
public:
    vector<string>ans;
    // rec 
    void helper(int n , string curr, int total,int open){
        if(curr.size()>total || open<0) return ; 
        if(curr.size()==total && open==0){
            ans.push_back(curr);
            return ;
        }
        // open brac 
        if(open<=n) helper(n,curr+'(',total,open+1);
        // close brac
        if(open>0) helper(n,curr+')',total,open-1);
    }
    
    vector<string> generateParenthesis(int n) {
        // rec
        helper(n,"",n*2,0);
        
        
        return ans;
    }
};