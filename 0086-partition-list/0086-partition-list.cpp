#include <iostream>

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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;
        ListNode* lessHead = new ListNode(0);
        ListNode* lessCurrent = lessHead;
        ListNode* greaterHead = new ListNode(0);
        ListNode* greaterCurrent = greaterHead;

        while (head) {
            if (head->val < x) {
                lessCurrent->next = head;
                lessCurrent = lessCurrent->next;
            } else {
                greaterCurrent->next = head;
                greaterCurrent = greaterCurrent->next;
            }
            head = head->next;
        }

        lessCurrent->next = greaterHead->next;
        greaterCurrent->next = nullptr;
        return lessHead->next;
    }
};
