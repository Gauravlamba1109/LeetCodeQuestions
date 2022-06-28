class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // we will keep a pq to have the trip end so that we can se 
        // if the curr node ; if the starting is more than the ending of a prev 
        sort(trips.begin(),trips.end(), [](const vector<int>&a , const vector<int>&b ){
           return a[1]<b[1]; 
        });
        // for(auto ele: trips)cout<<ele[0]<<","<<ele[1]<<","<<ele[2]<<endl;
        // cout<<endl;
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >q;
        
        // q.push({trips[0][2],0}); 
        int currcap =0;
        
        for(int i=0;i<trips.size();i++){
           // cout<<currcap<<";"<<q.top().first<<","<<q.top().second<<endl;
            vector<int> currt = trips[i];
            currcap += currt[0];
            while(q.size() && q.top().first<= currt[1] ){
                // this trip will move simult
                currcap -= trips[q.top().second][0];
                q.pop();
            }
            if(currcap>capacity) return false;
            q.push({currt[2],i});
        }
        
        return true;
    }
};