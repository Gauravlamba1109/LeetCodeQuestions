class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(),c.end());

        int val=0;
        int j=0;
        for(int i=c.size()-1; i>=0; i--){
            if(j+1 <= c[i]) {val=j+1; j++;}
            else break;
        }

        return val;
    }
};