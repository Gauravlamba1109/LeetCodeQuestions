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
        
        // starting node 
        m[node]=new Node(node->val);
        
        // using bfs
        queue<Node*>q;
        q.push(node);
        
        while(q.size()){
            Node* t = q.front();
            q.pop();
            
            // if curr node's already has some neighbours we dont need to use it 
            if(m.find(t)!=m.end() && m[t]->neighbors.size()!=0) continue;
            
            for(auto nei : t->neighbors){
                if(m.find(nei)==m.end()){
                    m[nei]=new Node(nei->val);
                    q.push(nei); // push because we need to clone its neib too 
                }
                // pushing copy of nei to copy of t 
                m[t]->neighbors.push_back(m[nei]);
            }
        }
        
        return m[node];
    }
};