class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0){
            n+=1;
            x= 1/x;
            return x*myPow(x,-n);
        }

        if( n%2 == 0 ){
            return myPow(x*x,n/2);
        }
        if( n%3 == 0 ){
            return myPow(x*x*x,n/3);
        }
        if( n%7 == 0 ){
            return myPow(x*x*x*x*x*x*x,n/7);
        }
        else{
            return x*myPow(x,n-1);
        }

        return 1;
    }
};