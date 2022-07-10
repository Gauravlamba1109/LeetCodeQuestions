class Solution {
public:
    string removeKdigits(string num, int k) {
        // monotonic stack 
        // basic idea is :
        // we have to delete peaks which are occuring before curr element
        // we can remove only k times 
        
        int n=num.size();
        if(n<=k) return "0";
        // used num as a stack itself 
        
        int i=-1;
        for(char & c : num){
            while( k>0 && i>-1 && num[i] > c ){ 
                                            // if curr is occuring after a peak ; del peak 
                i--;  k--;
            }
            num[++i] = c;                   // add curr to stack now 
        }

        while( i>-1 && k-- ) i--;           // if we can still remove ele , remove
        num = num.substr(0,i+1);              // cut stack from rem 
        
        i=0;
        while(i<num.size() && num[i] == '0' )
            i++;                            // index of non-0 starting ; del leading zeros 
        num = num.substr(i);                // cut 0s 
        
        return num=="" ? "0" : num;         // if all were 0s we are left with empty str 
    }
};
