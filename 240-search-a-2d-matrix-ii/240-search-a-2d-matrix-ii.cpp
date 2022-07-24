class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0 ;
        int j = matrix[0].size()-1;
        
        while(true){
            if(j<0 || i>=matrix.size()) return false;
            
            if(matrix[i][j]==target) return true;
            
            if(matrix[i][j]>target){
                j--; 
            }
            else if(matrix[i][j]<target){
                i++;
            }
        }
        
        return false;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // int j=matrix[0].size()-1;
        // int i=0;
        // while(true){
        //     if(j<0 || i>matrix.size()-1)break;
        //     if(matrix[i][j]==target)return true;
        //     if(matrix[i][j]<target){
        //         i++; continue;
        //     }    
        //     if(matrix[i][j]>target){
        //         j--; continue;
        //     }
        // }
        // return false;
    }
};