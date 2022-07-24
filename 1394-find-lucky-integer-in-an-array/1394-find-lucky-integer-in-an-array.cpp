class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>m;
        int ans = -1;
        for(auto e : arr){
            m[e]++;
        }
        for(auto e : m){
            if(e.first==e.second) ans=max(ans,e.first);
        }
        
        return ans;
    }
};