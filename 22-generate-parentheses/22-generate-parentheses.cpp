class Solution2 {
public:
    vector<string>ans;
    // rec 
    void helper(string curr, int total,int open){
        if(curr.size()>total || open<0) return ; 
        if(curr.size()==total && open==0){
            ans.push_back(curr);
            return ;
        }
        // open brac 
        if(open<=total/2) helper(curr+'(',total,open+1);
        // close brac
        if(open>0) helper(curr+')',total,open-1);
    }
    
    vector<string> generateParenthesis(int n) {
        // rec
        helper("",n*2,0);
        
        return ans;
    }
};


class Solution {
public:    
    vector<string> generateParenthesis(int n) {
        // rec + trick 
        // insert a valid case at every pos in para generated by n-1 
        if(n==1) return {"()"};
        set<string>set;
        
        for(auto str: generateParenthesis(n-1)){
            for(int i=0;i<str.size();i++){
                string a = str.substr(0,i)+"()"+str.substr(i);
                set.insert(a);
            }
        }
        vector<string>ans(set.begin(),set.end());
        return ans;
    }
};

