class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=10000;
        int n= blocks.size();  
        int cnt=0;
        for(int i=0;i<k;i++)
            if(blocks[i]=='W') cnt++;
        
        ans=cnt;
        for(int r=k;r<n;r++){
            if(blocks[r]=='W') cnt++;
            if(blocks[(r-k)]=='W') cnt--;
            ans=min(ans,cnt);
        }
        return ans;
    }
};

// BWBBWWBBBWB WWWBWWBBWBWBBWBB
