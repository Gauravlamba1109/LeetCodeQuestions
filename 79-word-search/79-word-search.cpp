class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    bool f = dfs(board,word,i,j,0);
                    if(f) return true;
                }
            }
        }
        return false;
    }
    
    vector<vector<int>>dir = {{0,1},{1,0},{-1,0},{0,-1}};
    bool dfs(vector<vector<char>>& board, string word,int i,int j,int k){
        if(k==word.size()) return true;
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0 || board[i][j]!=word[k]) return false;
        
        char temp = board[i][j];
        board[i][j]='.';
        
        bool t1 = dfs(board,word,i+1,j,k+1); if(t1) return true;
        bool t2 = dfs(board,word,i-1,j,k+1); if(t2) return true;
        bool t3 = dfs(board,word,i,j+1,k+1); if(t3) return true;
        bool t4 = dfs(board,word,i,j-1,k+1); if(t4) return true;

        board[i][j]=temp;
        
        return t1||t2||t3||t4;
    }
};








