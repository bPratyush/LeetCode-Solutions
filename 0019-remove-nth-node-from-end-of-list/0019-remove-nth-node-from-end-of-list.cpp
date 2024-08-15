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
    int getlen(ListNode* head){
        int n=0;
        ListNode* tmp=head;
        while(tmp){
            n++;
            tmp=tmp->next;
        }
        return n;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=getlen(head);
        if (n == len) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }
    int k = len - n;
    ListNode* tmp = head;
    while (k-- > 1) tmp = tmp->next;
    ListNode* nodeToRemove = tmp->next;
    tmp->next = tmp->next->next;
    delete nodeToRemove;
    return head;
    }
};