class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // bfs traversal 
        // make a graph 
        vector<int> arr[n];
        
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1)
            arr[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>>q;
        q.push({headID,informTime[headID]});
        int res = 0 ;  // max time 
        
        while(q.size()){
            int siz = q.size();
            for(int i=0;i<siz;i++){
                int currid = q.front().first;
                int currtm = q.front().second;
                q.pop();
                
                res = max(currtm,res);
                
                for(auto child : arr[currid]){
                    q.push({child,currtm+informTime[child]});
                }
            }
        }
        return res;
    }
};