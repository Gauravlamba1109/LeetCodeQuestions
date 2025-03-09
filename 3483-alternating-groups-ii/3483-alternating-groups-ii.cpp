class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // sliding window 
        // l is the starting point , compare starts with r till k eles are reached
        // after k ele reset l 

        int l=0;
        int r=1;
        int ans = 0;
        int n = colors.size() ;
        for(r=1; r< n+(k-1) ; r++){
            if(colors[r%n]==colors[(r-1)%n]){
                l = r; // adj ele are equal ; pattern break ; reset window ; 
            }
            if( r - l + 1 > k ){    // pattern confinues but window too big, shift left pointer 
                l ++ ; 
            }
            if( r - l + 1 == k ){
                ans ++ ; 
            }
        }

        return ans;
    }
};