class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
        return rec(s,0,p,0,dp);
    }

    bool rec(string &s, int i, string &p, int j,vector<vector<int>>&dp){
        if(i==s.size() && j==p.size()) return true;
        if(j==p.size()) return false ; // pattern over, string is not 

        if(i==s.size()){ // string is over
            // look for *, there should only be * for matching to succeed
            for(int k = j; k<p.size() ; k++) 
                if(p[k]!='*') 
                    return false;  

            return true;
        }
        
        if(i<s.size() && j<p.size() && dp[i][j]!=-1) return dp[i][j];

        // exact match 
        if( p[j] != '?' && p[j] != '*'){ 
            if( s[i] != p[j] ) return dp[i][j]=false;
            return dp[i][j]=rec(s,i+1,p,j+1,dp);
        }
        else if( p[j] == '?' ){
            return dp[i][j]=rec(s,i+1,p,j+1,dp);
        }
        else { // * can match zero or more chars
            return dp[i][j]=( rec(s,i+1,p,j,dp) || rec(s,i,p,j+1,dp) );
        }

    }
};