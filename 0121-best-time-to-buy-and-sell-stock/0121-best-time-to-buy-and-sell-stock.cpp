class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 
        vector<int>v;
        int m = prices[0];
        int ans = 0;
        for(auto e: prices) {
            m= min(m,e);
            v.push_back(m);
            ans = max(ans, e-m);
        }
        return ans;
    }
};