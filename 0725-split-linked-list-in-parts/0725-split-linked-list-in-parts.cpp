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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head;
        vector<ListNode*> parts(k, nullptr);
        while (curr) {
            len++;
            curr = curr->next;
        }
        int sz = len / k, extra = len % k;
        curr = head;
        for (int i = 0; i < k; i++) {
            int partSize = sz + (extra > 0 ? 1 : 0);
            extra--;
            if (partSize == 0) {
                parts[i] = nullptr;
                continue;
            }
            ListNode* partHead = curr, * partTail = curr;
            for (int j = 1; j < partSize; j++) partTail = partTail->next;
            curr = partTail->next;
            partTail->next = nullptr;
            parts[i] = partHead;
        }
        return parts;
    }
};
