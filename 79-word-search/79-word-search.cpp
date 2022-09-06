class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // backtracking 
        
        for(int i = 0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    set<pair<int,int>>p;
                    bool t = dfs(i,j,board,word,0,p);
                    if(t) return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(int i,int j , vector<vector<char>>& board, string &word, int idx, set<pair<int,int>>&path){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[idx]){
            return false;
        }

        if(idx==word.size()-1)return true;
        
        board[i][j]='#';
        
        if (dfs(i+1,j,board,word,idx+1,path)
            ||dfs(i-1,j,board,word,idx+1,path)
            ||dfs(i,j+1,board,word,idx+1,path)
            ||dfs(i,j-1,board,word,idx+1,path))return true;
        
        board[i][j]=word[idx];
        return false;
        
    }
};