class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool>m;
        while(n!=1 && m.find(n)==m.end()){
            m[n]=1;
            
            int nn = 0;
            
            while(n>0){
                nn+= (n%10)*(n%10);
                n=n/10;
            }
            
            n=nn;
        }
        
        return n==1;
    }
};