class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int pos=0;
        while(i<chars.size()){
            int j=i;
            int cnt=0;
            while(j<chars.size() && chars[i]==chars[j]){
                j++;
                cnt++;
            }
            // cout<<cnt<<" ";
            if(cnt==1){
                chars[pos]=chars[i];
                pos++;
                i++;
            }
            else{
                chars[pos]=chars[i];
                pos++;
                string c = to_string(cnt);
                while(c.size()){
                    chars[pos]=c[0];
                    c=c.substr(1);
                    pos++;
                }
                i=j;
            }
     
        }
        return pos;
    }
};