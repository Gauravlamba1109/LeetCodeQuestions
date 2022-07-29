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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) return NULL;
        // dummy pointer 
        ListNode* slow = new ListNode(-1); 
        slow->next=head;
        ListNode* fast = slow;
        
        head=slow;  // head ponting to dummy node 
        
        while(fast!=NULL && n>=0){ n--; fast=fast->next;}
        
        while(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        
        slow->next=slow->next->next;
        return head->next;
    }
};