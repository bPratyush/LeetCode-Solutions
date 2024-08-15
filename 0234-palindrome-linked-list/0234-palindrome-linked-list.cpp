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
    void reverse(struct ListNode** head_ref){
    struct ListNode* prev = NULL;
    struct ListNode* curr = *head_ref;
    struct ListNode* next = NULL;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head_ref = prev;
}

bool isPalindrome(struct ListNode* head) {
    if(!head || !head->next) return true;
    struct ListNode *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    reverse(&slow);
    struct ListNode* curr = head;
    while(slow) {
        if(curr->val != slow->val) return false;
        curr = curr->next;
        slow = slow->next;
    }
    return true;
}
};