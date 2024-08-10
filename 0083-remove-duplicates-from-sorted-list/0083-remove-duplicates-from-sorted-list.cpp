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
   ListNode* deleteDuplicates(ListNode* head) {
    vector<int> res;
    ListNode* temp = head;
    while (temp) {
        res.push_back(temp->val);
        temp = temp->next;
    }
    sort(res.begin(), res.end());
    auto last = unique(res.begin(), res.end());
    res.erase(last, res.end());
    ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        for (int value : res) {
            current->next = new ListNode(value);
            current = current->next;
        }

        return dummy->next;
}
};