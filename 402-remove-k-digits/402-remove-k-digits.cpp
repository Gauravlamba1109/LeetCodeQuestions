class Solution {
public:
    string removeKdigits(string num, int k) {
        // monotonic stack 
        int n=num.size();
        if(n<=k) return "0";
        int i=-1;
        for(char &c:num){
            while(k>0 && i>-1 && num[i]>c){
                i--;
                k--;
            }
            // if(i>-1 && c!='0') 
                num[++i]=c;
        }
        // cout<<num<<" "<<i<<endl;
        while(i>-1 && k--)i--;
        num=num.substr(0,i+1); // cut rem 
        i=0;
        
        while(i<num.size() && num[i]=='0'){
            i++;
        }
        num=num.substr(i); // cut 0s 
        if(num=="") return "0";
        return num;
    }
};