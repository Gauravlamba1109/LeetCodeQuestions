class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int maxl = 0;
        for(int i=0;i<a.size()+b.size()-1;i++){
            int sa = max(0,(int)(a.size()-1-i)); // (m-1)-i
            int sb = max(0,(int)(i-a.size()+1)); // i-(m-1)
            int cnt=0;
            
            for(;sa<a.size() && sb<b.size() ; sa++ , sb++){
                if(a[sa]==b[sb]){
                    cnt++;
                    maxl=max(cnt,maxl);
                }
                else cnt=0;
            }
        }
        return maxl;
    }
};