class Solution {
public:
    int fib(int n) {
        // nth = n-1th + n-2th 
        int n0,n1,ans;
        n0 = 0; 
        n1 = 1;
        if(n==0)return 0;
        if(n==1)return 1;
        for(int i=2;i<=n;i++){
            ans=n1+n0;
            int t=n1;
            n1=ans;
            n0=t;
        }
        return ans;
    }
};