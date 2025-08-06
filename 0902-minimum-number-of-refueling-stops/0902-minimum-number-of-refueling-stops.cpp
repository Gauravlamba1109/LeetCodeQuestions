class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // greedy 

        priority_queue<int>maxh;
        int stops = 0;
        int fuel = startFuel;
        int i =0, n = stations.size();

        // while you are away from target 
        while( fuel< target ){
            
            // if reachable then add to maxheap
            while( i<n && stations[i][0]<=fuel){
                maxh.push(stations[i][1]);
                i++;
            }

            // if no stations left then you cannot reach target 
            if( maxh.empty()) return -1;

            // fuel-up with largest in reach next
            fuel += maxh.top();
            maxh.pop();
            stops++;

        }

        return stops;
    }
};