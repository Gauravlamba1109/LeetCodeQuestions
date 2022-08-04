class Solution {
public:
    map<string,int>m;
    int mirrorReflection(int p, int q) {
        while(p%2==0 && q%2==0){
            p/=2; q/=2;
        }    
        
        if(p%2==0) return 2;
        if(q%2==0) return 0;
        return 1;
    }
};


// If p = odd, q = even: return 0
// If p = even, q = odd: return 2
// If p = odd, q = odd: return 1