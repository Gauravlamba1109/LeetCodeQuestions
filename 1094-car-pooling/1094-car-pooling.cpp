class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // we will keep a pq to have the trip end so that we can se 
        // if the starting is more than the ending of a prev
        // then we pop the trips which ended ; and add the curr trip to q
        
        sort(trips.begin(),trips.end(), [](const vector<int>&a , const vector<int>&b ){
           return a[1]<b[1]; 
        });

        
        // to get the latest trip which ended ; push trip-end and index
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >q;
        
        // starting cap 
        int currcap =0;
        
        for(int i=0;i<trips.size();i++){
            vector<int> currt = trips[i];
            currcap += currt[0];
            
            // del ended trips 
            while(q.size() && q.top().first<= currt[1] ){
                currcap -= trips[q.top().second][0];
                q.pop();
            }
            // exceeded cap 
            if(currcap>capacity) return false;
            // add curr trip 
            q.push({currt[2],i});
        }
        
        return true;
    }
};