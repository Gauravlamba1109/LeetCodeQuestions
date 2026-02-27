class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,bool>m;
        for(auto e : bulbs){
            m[e]=!m[e];
        }
        vector<int>ans;
        for(auto e : m){
            if(e.second){
                ans.push_back(e.first);
            }
        }

        return ans;
    }
};