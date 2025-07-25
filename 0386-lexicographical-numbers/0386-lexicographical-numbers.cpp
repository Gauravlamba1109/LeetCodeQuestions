class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // dfs
        vector<int>lex;
        for(int i=1;i<9;i++){
            dfs(i,n,lex);
        }
        return lex;        
    }

    void dfs(int i, int n, vector<int>&lex){
        if(i>n || lex.size()>=n) return;

        lex.push_back(i);

        if(10*i<=n) dfs(10*i, n, lex);
        else {
            while( i % 10 == 9 || i>=n ) i/=10;        
            dfs(i+1,n,lex);
        }
        
        return ; 
    }




};