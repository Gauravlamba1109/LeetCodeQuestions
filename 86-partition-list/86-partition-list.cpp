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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(0);
        ListNode* right = new ListNode(0);
        ListNode* resr = right;
        ListNode* resl = left;
        while(head!=NULL){
            if(head->val>=x){
                left->next = new ListNode(head->val);
                left = left->next;
            }else{
                right->next= new ListNode(head->val);
                right = right->next;
            }
            head = head->next;
        }
        
        right->next = resl->next;
        
        return resr->next;
    }
};