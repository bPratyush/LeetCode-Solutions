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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int> mergedValues;
        for (ListNode* list : lists) {
            while (list) {
                mergedValues.push_back(list->val);
                list = list->next;
            }
        }
        sort(mergedValues.begin(), mergedValues.end());

        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        for (int value : mergedValues) {
            current->next = new ListNode(value);
            current = current->next;
        }
        return dummy->next;
    }
};