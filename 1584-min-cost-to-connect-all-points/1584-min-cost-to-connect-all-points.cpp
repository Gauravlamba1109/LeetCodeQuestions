class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // min spanning tree 
        // prims algorithm
        // n-1 edges required 
        
        unordered_map<int,vector<pair<int,int>>>m;        
        vector<int>visited(points.size(),0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int t = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                m[i].push_back({t,j});
                m[j].push_back({t,i});                
            }    
        }
        q.push({0,0}); //cost,index
        int ans=0, vis=0;
        while(vis<points.size()){
            pair<int,int>f = q.top(); q.pop();
            int dist = f.first , nod = f.second;
            
            if(visited[nod]) continue;
            visited[nod]=1; vis++;
            
            ans+=dist;

            for(auto nei: m[nod]){
                q.push(nei);
            }
        }
        
        return ans;
    }
};