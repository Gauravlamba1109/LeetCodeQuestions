class Solution {
public:
    string fractionToDecimal(int anum, int aden) {
        string sign="";
        int flag = 1;
        if(anum<0) flag=-1;
        if(aden<0) flag*=-1;
        if(flag==-1) sign = "-";
        long num = labs(anum);
        long den = labs(aden);
        
        
        long q = num/den;
        long r = num%den;
        string ans="" ;
        ans+=to_string(q);
        map<int,string>s;
        if(r==0){
            if(ans=="0") return ans;
            return sign+ans;
        }else{
            ans+=".";
            
            while(r!=0){
                r*=10;
                q = r/den;
                r = r%den;
                ans+=to_string(q);
                if(s.find(r)!=s.end()){
                    string res = ans.substr(s[r].size());
                    ans = s[r]+"("+res+")";
                    return sign+ans;
                }
                s[r]=ans;
            }
        }
        return sign+ans;
    }
};