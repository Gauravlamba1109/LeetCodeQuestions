class Solution {
private:
    int find(int node){
        if(parent[node]== -1) return node;
        return parent[node]=find(parent[node]);
    }
    void Union(int node1,int node2){
        int r1 = find(node1);
        int r2 = find(node2);

        if(r1 == r2) return;
        if(depth[r1]<depth[r2]) swap(r1,r2);
        parent[r2]=r1;
        if(depth[r1]==depth[r2]) depth[r1]++; 
    }
public:
    vector<int> parent;
    vector<int> depth;
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n,-1);
        depth.resize(n,0);

        vector<unsigned int> componentCost(n,-1);
        for(auto& e : edges) Union(e[0],e[1]);

        for(auto& e : edges) componentCost[find(e[0])] &=e[2];
        
        vector<int> ans;
        for(auto& q : query){
            if(find(q[0])!=find(q[1])) ans.push_back(-1);
            else ans.push_back(componentCost[find(q[0])]);            
        }
        
        return ans;
    }
    
};