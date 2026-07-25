class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[301]={0};
        dp[s.size()]=true;

        for(int i=s.size()-1;i>=0;i--){
            for( string w : wordDict){
                if( i + w.size() <= s.size() &&
                    s.substr(i,w.size())==w
                )
                    dp[i]=dp[i+w.size()];
                else 
                    dp[i]=false;

                if(dp[i]) break;
            }

        }
            return dp[0];

    }
};