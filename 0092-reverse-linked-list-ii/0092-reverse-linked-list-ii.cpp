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
    ListNode* reverse(ListNode* head){
        if(!head) return NULL;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; ++i) prev = prev->next;

        //Identify the `start` node and `end` node of the sublist
        ListNode* start = prev->next;
        ListNode* end = start;
        for (int i = 0; i < right - left; ++i) end = end->next;

        //Detach the sublist
        ListNode* after = end->next;
        end->next = nullptr;

        //Reverse the sublist
        ListNode* reversedSublist = reverse(start);

        //Reattach the reversed sublist back to the original list
        prev->next = reversedSublist;
        start->next = after;
        return dummy->next;
    }
};