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
   ListNode* reverse(ListNode* head, ListNode* tail) {
    ListNode* curr = head;
    ListNode* prev = NULL;
    
    while (curr != tail) {
        ListNode* fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    
    return prev; // Return the new head after reversal
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* tmp = head;
    for (int i = 0; i < k; ++i) {
        if (!tmp) return head;
        tmp = tmp->next;
    }
    ListNode* newHead = reverse(head, tmp);
    head->next = reverseKGroup(tmp, k);
    return newHead;
}
};