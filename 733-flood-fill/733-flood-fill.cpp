class Solution {
public:
    void dfs(vector<vector<int>>&image, int i , int j,int color, int currc){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=currc || image[i][j]==color) return ; 
        image[i][j]=color;
        
        if((i+1)<image.size() && image[i+1][j]==currc) 
            dfs(image,i+1,j,color,currc);
        
        if((j+1)<image[0].size() && image[i][j+1]==currc) 
            dfs(image,i,j+1,color,currc);
        
        if((i-1)>=0 && image[i-1][j]==currc) 
            dfs(image,i-1,j,color,currc);
        
        if((j-1)>=0 && image[i][j-1]==currc) 
            dfs(image,i,j-1,color,currc);
        
        return ;
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // do simple dfs from sr,sc
        
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size()) return image; 
        int currc = image[sr][sc];
        dfs(image,sr,sc,color,currc);
        
        return image;
    }
};