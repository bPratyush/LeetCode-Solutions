class Solution {
public:
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) { // renamed from 'merge' to 'mergeTwoLists'
    if(!list1) return list2;
    if(!list2) return list1;
    ListNode* ptr=new ListNode(-1);
    ListNode* curr=ptr;
    while(list1&&list2){
        if(list1->val<list2->val){
            curr->next=list1;
            list1=list1->next;
        }
        else{
            curr->next=list2;
            list2=list2->next;
        }
        curr=curr->next;
    }
    if(!list1) curr->next=list2;
    if(!list2) curr->next=list1;
    return ptr->next;
}
};
