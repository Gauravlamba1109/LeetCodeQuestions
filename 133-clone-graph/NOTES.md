```
class Solution {
public:
vector<Node*>copies;
Node* cloneGraph(Node* node) {
if(!node) return NULL;
Node* head=new Node(node->val,{});
copies.push_back(head);
queue<Node*>q;
q.push(node);
while(!q.empty()){
Node* curr=q.front();
q.pop();
for(auto nei : curr->neighbors){
if(find(copies.begin(),copies.end(),nei)==copies.end()){
Node* neigh=new Node(nei->val,{});
copies.push_back(neigh);
q.push(nei);
int ind=find(copies.begin(),copies.end(),curr)-copies.begin();
copies[ind]->neighbors.push_back(neigh);
}
}
}
return head;
}
};
```