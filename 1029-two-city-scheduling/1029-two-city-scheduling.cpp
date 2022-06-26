class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        unordered_map<string,int>m;
        return helper(costs,0,0,m);
        
    }
    int helper(vector<vector<int>>&cost,int ca, int i,unordered_map<string,int>&m){
        if(i>=cost.size()){
            if(ca==0)
                return 0;
            else return 1e9;
        }
        
        string s = to_string(ca)+"."+to_string(i) ;
        if(m[s]) return m[s];
        int c1h = cost[i][0]+helper(cost,ca+1,i+1,m);
        int c2h = cost[i][1]+helper(cost,ca-1,i+1,m);
        
        return m[s]=min(c1h,c2h);
    }
};