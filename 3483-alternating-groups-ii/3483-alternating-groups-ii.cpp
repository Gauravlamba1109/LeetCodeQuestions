class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int cnt = 1 ; 
        int prev = colors[0];
        int n = colors.size();
        int ans = 0 ;
        for(int i=0;i<n+k-1;i++){
            if(colors[i%n]==prev) {
                cnt = 1;
            }else{
                cnt ++ ;
                if( cnt >= k) ans++; // found one more alternating window
            }
            prev= colors[i%n];
        }
        return ans;
    }
};