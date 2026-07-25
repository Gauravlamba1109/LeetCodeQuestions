class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = cost[cost.size()-1];
        int b = 0;
        int ans = INT_MAX-1000;
        for(int i=cost.size()-2;i>=0;i--){
            ans = INT_MAX-1000;
            ans = cost[i]+min(a,b);
            b=a;
            a=ans;
        }

        return min(a,b);
    }
};