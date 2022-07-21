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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 
        if(head==NULL) return NULL;
        // move to left 
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(m>1){
            prev=curr;
            curr=curr->next;
            m--;
            n--;
        }
        ListNode* res = prev;
        ListNode* tail= curr;
        // curr is on left pos 
        // we can start reversing till n is 0 
        while(n>0){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev=curr;
            curr=nex;
            n--;
        }
        
        // r   t     p  c
        // 1-> 2<-3<-4  5
        if(res) res->next=prev;
        else head = prev;
        tail->next= curr;
        
        return head;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         //empty list
//         if(head==NULL) return NULL;
//         ListNode* cur = head , pre = NULL;
//         while(m>1){
//             pre=cur;
//             cur=cur->next;
//             m--; n--;
//         }
//         //now curr is on position 
//         ListNode* con=pre, tail=cur;
//         ListNode* thrid=NULL;
        
//         //reverse iteratively
//         while(n>0){
//             third=cur->next;
//             cur->next=pre;
//             pre=cur;
//             cur=third;
//             n--;
//         }
//         if(con!=NULL) con->next=pre;
//         else head=pre;
        
//         tail->next=cur;
//         return head;
    }
};







