class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        
        int l1 = num1.size();
        int l2 = num2.size();
        
        int len = l1+l2 ;
        vector<int>ans(len,0);
        
        for(int i=l1-1 ; i>=0 ; i--){
            int cc = num1[i]-'0' ;
            for(int j=l2-1 ; j>=0 ; j--){
                int ccb = num2[j]-'0' ;
                int ind = i+j+1;
                int p = cc*ccb + ans[ind];
                ans[ind] = p%10;
                ans[ind-1]+=p/10;
            }
        }
        
        int start = ans[0]!=0 ? 0 : 1 ;
        string res="";
        for(int i=start ; i<len ; i++){
            res+=(ans[i]+'0');
        }
        return res;
    }
};