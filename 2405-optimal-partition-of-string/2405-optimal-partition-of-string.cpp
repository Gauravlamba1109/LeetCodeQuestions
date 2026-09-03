class Solution {
public:
    int partitionString(string s) {
        bool seen[26] ={};
        int ans=1;
        for(char e:s){
            if(seen[e-'a']){
                ans++;
                fill(begin(seen),end(seen),false);
            }
            seen[e-'a']=1;
        }

        return ans;
    }
};