//         ListNode* front=head;
//         ListNode* behin=head;
//         while(front!=NULL){
//             front=front->next;
//             if(n--<0)behin=behin->next;
//         }
//         if(n==0)head=head->next;
//         else behin->next = behin->next->next;
//         return head;
//         //or
//         //more advanced
//         ListNode* *t1=&head, *t2=head;
//         for(int i=1;i<n;i++){
//             t2=t2->next;
//         }
//         while(t2->next!=NULL){
//             t1=&((*t1)->next);
//             t2=t2->next;
//         }
//         *t1=(*t1)->next;
//         return head;
```
```
```
​