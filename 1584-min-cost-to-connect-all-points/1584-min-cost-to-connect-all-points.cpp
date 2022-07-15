class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // transform to nodes 
        map<int,vector<pair<int,int>>>m;
        
        for(int node = 0 ;node<points.size();node++){
            for(int i=0;i<points.size();i++){
                if(node==i)continue;
                int dis = abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1]);
                m[node].push_back({dis,i});
                m[i].push_back({dis,node});
            }
        }
        int n=points.size();
        int key[n]; // store the dist connecting i 
        int mst[n]; // is i part of mst ;
        for(int i=0;i<n;i++){
            key[i]=1e9;
            mst[i]=0;
        }
        
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;
        
        key[0]=0;
        pq.push({0,0});
        int ans=0;
        while(pq.size()>0){
            int curr = pq.top().second;

            pq.pop();
            mst[curr]=1;
            for(auto nbrs : m[curr]){
                int nbr = nbrs.second;
                int dis = nbrs.first;
                
                if(!mst[nbr] && dis < key[nbr]){
                    key[nbr]= dis;
                    pq.push({key[nbr],nbr});
                }
            }
        }
        ans=0;
        for(int i=0;i<n;i++){
            ans+=key[i];
        }
        return ans;
        
    }
};