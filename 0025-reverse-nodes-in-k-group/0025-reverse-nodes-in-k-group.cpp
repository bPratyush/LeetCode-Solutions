class Solution {
public:
    void reverse(ListNode* start, ListNode* end) {
        ListNode* curr = start;
        ListNode* prev = NULL;
        while (curr != end) {
            ListNode* fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        curr->next = prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode* s = head;
        ListNode* e = head;
        int inc = k - 1;
        while (inc--) {
            e = e->next;
            if (!e) return head;
        }
        ListNode* nextHead = reverseKGroup(e->next, k);
        reverse(s, e);
        s->next = nextHead;
        return e;
    }
};