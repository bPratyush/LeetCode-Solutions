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
ListNode* rev(ListNode* head){
    ListNode* prev=NULL;
    ListNode* curr=head;
    while(curr){
        ListNode* fwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
    }
    return prev;
}

void merge(ListNode* head1, ListNode* head2){
    while(head2){
        ListNode* fwd1=head1->next;
        ListNode* fwd2=head2->next;
        head1->next=head2;
        head2->next=fwd1;
        head1=fwd1;
        head2=fwd2;
    }
}

void reorderList(ListNode* head){
    if(!head||!head->next||!head->next->next) return;
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* l1=head;
    ListNode* l2=rev(slow->next);
    slow->next=NULL;
    merge(l1,l2);
    }
};