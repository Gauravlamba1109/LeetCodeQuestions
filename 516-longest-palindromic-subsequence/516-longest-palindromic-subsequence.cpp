class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // lcs in s and rev s
        string a = s;
        string b = s;
        reverse(b.begin(),b.end());
        
        vector<vector<int>>m(a.size()+1,vector<int>(b.size()+1,0));
        if(a.size()==0 || b.size()==0) return 0 ;
        
        for(int ap=a.size()-1;ap>=0;ap--){
            for(int bp=b.size()-1;bp>=0;bp--){
                
                if(a[ap]==b[bp]){
                    m[ap][bp] = 1 + (((ap+1)<a.size() && (bp+1)<b.size())? m[ap+1][bp+1] :0);
                }
                else 
                    m[ap][bp]=max( (((ap+1)<a.size())?m[ap+1][bp]:0) , (((bp+1)<b.size())?m[ap][bp+1]:0) );
            }
        }
        return m[0][0];
    }
};