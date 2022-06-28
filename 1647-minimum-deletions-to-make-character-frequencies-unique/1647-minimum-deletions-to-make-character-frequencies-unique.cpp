class Solution {
public:
    int minDeletions(string s) {
        vector<int>v(28,0);
        for(auto c:s) v[c-'a']++;
        int cnt=0;
        set<int>seen;
        for(int i=0;i<v.size();i++){
            int currc=0;
            while(v[i]>0 && seen.find(v[i])!=seen.end()){
                v[i]=v[i]-1;
                cnt++;
            }
            seen.insert(v[i]);
        }
        return cnt;
    }
};