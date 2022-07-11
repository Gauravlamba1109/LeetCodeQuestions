/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        
        unordered_map<Node*,Node*>m;
        m[node]=new Node(node->val,{});
        // bfs 
        queue<Node*>q;
        q.push(node);
        
        while(q.size()){
            Node* t = q.front(); q.pop();
            if(m.find(t)!=m.end() && m[t]->neighbors.size()!=0)continue;
            
            for(auto nei : t->neighbors){
                if(m.find(nei)==m.end()){
                    m[nei]=new Node(nei->val,{});
                    q.push(nei);
                }
                m[t]->neighbors.push_back(m[nei]);
            }
        }
        
        return m[node];
    }
};