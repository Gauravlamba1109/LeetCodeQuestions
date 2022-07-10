```
/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;
Node(int _val) {
val = _val;
next = NULL;
random = NULL;
}
};
*/
​
class Solution {
public:
Node* copyRandomList(Node* head) {
map<Node*,Node*>m;
Node* res = head ;
while(head!=NULL){
m[head]=new Node(head->val);
head = head->next ;
}
Node* dum = new Node(-1);
res = dum;
for(auto n : m){
dum->next = n.second;
dum = dum->next;
dum->random = m[n.first->random];
}
return res->next;
}
};
```