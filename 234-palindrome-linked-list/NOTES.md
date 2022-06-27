t=t->next;
}
while(head!=NULL){
if(st.top()!=head->val)return false;
st.pop();
head=head->next;
}
return true;
}
};
​
public boolean isPalindrome(ListNode head) {
ListNode temp = head;
Stack stack = new Stack();
while (temp != null) {
stack.push(temp.val);
temp = temp.next;
}
while (head != null) {
if (head.val != (int)stack.pop()) {
return false;
}
head = head.next;
}
return true;
}
```