class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string nn = to_string(n);
        sort(nn.begin(),nn.end());
        for(int i=0;i<=31;i++){
            int p = 1 << i;
            string pp = to_string(p);
            sort(pp.begin(),pp.end());
            if( pp == nn ) return true;
        }

        return false;
    }
};