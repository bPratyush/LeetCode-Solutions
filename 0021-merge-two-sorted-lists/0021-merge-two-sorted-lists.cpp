class Solution {
public:
    struct ListNode* merge(struct ListNode* list1, struct ListNode* list2) {
    if(!list1) return list2;
    if(!list2) return list1;
    if(list1->val<list2->val) {
        list1->next=merge(list1->next,list2);
        return list1;
    }
    else{
        list2->next=merge(list1,list2->next);
        return list2;
    }
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) { // renamed from 'merge' to 'mergeTwoLists'
    struct ListNode* tmp = merge(list1,list2);
    return tmp;
}
};
