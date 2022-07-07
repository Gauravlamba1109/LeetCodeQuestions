class Solution {
public:
    bool isSameAfterReversals(int num){
        int n = to_string(num).size();
        if(n==1) return true;
        return num%10!=0 ;
    }
};