class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // rec with memo 
        // unordered_map<string,int>m;
        // return helper(costs,0,0,m);
        
        //greedy
        priority_queue<pair<int,int>>m; 
        int ind=0;
        for(auto ele : costs){
            m.push({(ele[0]-ele[1]),ind});
            ind++;
        }
        
        int n = costs.size();
        int cnt=0;
        int amt = 0;
        while(m.size()){
            pair<int,int> ele = m.top(); 
            m.pop();
            
            if(cnt++ >= n/2){ //b
                amt+=costs[ele.second][0];
            }else{//a
                amt+=costs[ele.second][1];
            }
        }
        
        return amt;
    }
//     int helper(vector<vector<int>>&cost,int ca, int i,unordered_map<string,int>&m){
//         if(i>=cost.size()){
//             if(ca==0)
//                 return 0;
//             else return 1e9;
//         }
        
//         string s = to_string(ca)+"."+to_string(i) ;
//         if(m[s]) return m[s];
//         int c1h = cost[i][0]+helper(cost,ca+1,i+1,m);
//         int c2h = cost[i][1]+helper(cost,ca-1,i+1,m);
        
//         return m[s]=min(c1h,c2h);
//     }
};