class Solution {
public:
    int partitionString(string s) {
        set<char>seen;
        int ans=1;
        for(char e:s){
            if(seen.contains(e)){
                ans++;
                seen.clear();
            }
            seen.insert(e);
            
        }

        return ans;
    }
};