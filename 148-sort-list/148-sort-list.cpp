/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        priority_queue<int>q;
        
        ListNode*res = head;
        while(res){
            q.push(-1*(res->val));
            res = res->next;
        }
        
        res=head;
        while(res){
            res->val= q.top()*-1 ;
            q.pop();
            res = res->next;
        }
        return head;
    }
};