class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // iterative approach 
        int start = 1 ;
        vector<int>lex;
        int i=0;

        while(i<n){
            lex.push_back(start);

            if(start*10<=n){
                start*=10;
            } else{
                while(start%10==9 || start>=n) start/=10;
                start+=1;
            }

            i++;   
        }

        return lex;
    }
};