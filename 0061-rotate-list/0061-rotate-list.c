struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || !k) return head;
    int n = 1;
    struct ListNode* tail = head;
    while (tail->next) {
        n++;
        tail = tail->next;
    }
    k = k % n;
    if (k == 0) return head;
    struct ListNode* newTail = head;
    for (int i = 0; i < n - k - 1; i++) newTail = newTail->next;
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;
    tail->next = head;
    return newHead;
}