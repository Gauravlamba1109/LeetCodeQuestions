class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int>m;
        for(auto e : bulbs){
            m[e]++;
        }
        vector<int>ans;
        for(auto e : m){
            if(e.second%2){
                ans.push_back(e.first);
            }
        }

        return ans;
    }
};