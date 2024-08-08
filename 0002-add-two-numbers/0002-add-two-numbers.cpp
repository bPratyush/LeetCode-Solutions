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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp1=l1;
        ListNode* tmp2=l2;
        ListNode* result=new ListNode(0);
        ListNode* current=result;
        int carry=0;
        while(tmp1||tmp2||carry){
            int sum=(tmp1?tmp1->val:0)+(tmp2?tmp2->val:0)+carry;
            carry=sum/10;
            current->next=new ListNode(sum%10);
            current=current->next;
            if(tmp1) tmp1=tmp1->next;
            if(tmp2) tmp2=tmp2->next;
        }
        return result->next;
    }
};