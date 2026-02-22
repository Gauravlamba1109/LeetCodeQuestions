class Solution {
public:
    int fact[10]={1,1,2,6,24,120,720,5040,40320,362880};

    bool isDigitorialPermutation(int n) {
        unordered_map<int,int>digits;
        int sum=0;
        while(n>0){
            int d = n%10;
            n/=10;
            digits[d]++;
            sum+= fact[d];
        }

        while(sum>0){
            int d = sum%10;
            sum/=10;
            digits[d]--;
            if(digits[0]<0)return false;
        }

        for(auto e: digits){
            if(e.second!=0) return false;
        }

        return true;

    }
};