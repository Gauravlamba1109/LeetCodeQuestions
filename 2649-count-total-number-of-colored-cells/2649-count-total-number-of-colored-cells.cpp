class Solution {
public:
    long long coloredCells(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 5;

        return (long long )2*(n-1)*(n-2)+(n-1)*4+1;


        // 4*red = e*e - e*(e+1)/2;
        //     = e(2*e-e-1)/2;
        //     =e(e-1)/2;
        //     =2*(n-1)(n-2);
        // middle = n-1*4+1


    }
};