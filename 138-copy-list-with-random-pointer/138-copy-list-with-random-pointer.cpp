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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // create copy of all nodes 
        unordered_map<Node*,Node*>m;
        m[NULL]=NULL;
        
        Node* res = head;
        while(res){
            m[res]= new Node(res->val);
            res=res->next;
        }
        res = head;
        Node* head2 = m[head];
        
        while(head2){
            head2->next = m[head->next];
            head2->random = m[head->random];
            head2 = head2->next;
            head  = head->next;
        }
        
        return m[res];
    }
};