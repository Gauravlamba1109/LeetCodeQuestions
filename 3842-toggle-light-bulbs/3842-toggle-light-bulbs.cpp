class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool>m(101,0);
        for(auto e : bulbs){
            m[e]=!m[e];
        }
        vector<int>ans;
        for(int e=0;e<m.size();e++){
            if(m[e]){
                ans.push_back(e);
            }
        }

        return ans;
    }
};