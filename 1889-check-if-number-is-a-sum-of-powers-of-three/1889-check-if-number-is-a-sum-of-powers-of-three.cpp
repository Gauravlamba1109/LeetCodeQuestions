class Solution {
public:
    bool checkPowersOfThree(int n) {
        if(n==0) return true;
        // return rec(0,n);

        int powr = 0;
        while( pow(3,powr)<= n ) powr++ ;

        while( n>0 ){
            if(n>=pow(3,powr)) n-=pow(3,powr);
            if(n>=pow(3,powr)) return false;
            powr--;
        } 
        return true;
    }

    // bool rec(int power, int n){
    //     if(n==0) return true;
    //     if(pow(3,power)>n) return false;
    //     bool addpow = rec(power+1, n-pow(3,power));
    //     bool skipow = rec(power+1, n );

    //     return addpow || skipow ; 
    // }
};