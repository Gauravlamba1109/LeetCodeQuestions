class Solution {
public:
    string maximumXor(string s, string t) {
        // x-or -> 
        // 1 0 > 1
        // 0 1 > 1
        // 1 1 > 0
        // 0 0 > 0
        int o = 0, z = 0;

        for(auto e : t){
            if(e=='1')o++;
            else z++;
        }

        string ans="";
        for(auto e : s){
            if(e=='1'){
                if(z){
                    z--;
                    ans+='1';
                }else{
                    o--;
                    ans+='0';
                }
            }else{
                if(o){
                    o--;
                    ans+='1';
                }else{
                    z--;
                    ans+='0';
                }
            }
        }

        return ans;
    }

    // 1111


};