class Solution {
public:
    void bfs(vector<int>& edges, int node, vector<int>&path){
        int n = edges.size();
        queue<int>q;
        q.push(node);
        path[node]=0;
        while(q.size()){
            int t = q.front(); q.pop();
            path.push_back(t);
            // if unvisited and visitable
            if(edges[t]!=-1 && path[edges[t]]==INT_MAX){
                q.push(edges[t]);
                path[edges[t]]=path[t]+1;
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // we have to find the lowest common child here 
        // we can find the distance from node1 to every node 
        // we can find the distance from node2 to every node 
        
        int n=edges.size();
        vector<int> arr[n];
        for(int i=0;i<edges.size();i++){
            arr[i].push_back(edges[i]);
        }
        vector<int>p1(n,INT_MAX),p2(n,INT_MAX);
        bfs(edges,node1,p1);
        bfs(edges,node2,p2);
            
        int res=INT_MAX, t=-1;
        for(int i=0;i<n;i++){
            // cout<<p1[i]<<" "<<p2[i]<<endl;
            if(p1[i]==INT_MAX || p2[i]==INT_MAX) continue;
            if(res> max(p1[i],p2[i])){
                res = max(p1[i],p2[i]);
                t = i;
            }
        }
        return t;
    }
};