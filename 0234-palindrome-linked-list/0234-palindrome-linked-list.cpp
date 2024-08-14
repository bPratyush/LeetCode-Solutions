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
    int getLength(ListNode* head) {
    int n = 0;
    ListNode* tmp = head;
    while (tmp) {
        n++;
        tmp = tmp->next;
    }
    return n;
}

ListNode* reverse(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = NULL;
    while (curr) {
        ListNode* fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    int n=getLength(head);
    ListNode* tmp = head;
    for (int i = 0; i < n / 2; i++) {
        tmp = tmp->next;
    }
    ListNode* tmp1 = reverse(tmp);
    ListNode* ptr1 = head;
    ListNode* ptr2 = tmp1;
    while (ptr2) {
        if (ptr1->val != ptr2->val) return false;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return true;
}
};