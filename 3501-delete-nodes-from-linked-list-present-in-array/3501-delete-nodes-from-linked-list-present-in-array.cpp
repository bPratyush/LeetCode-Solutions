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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
       unordered_set<int> seti(nums.begin(),nums.end());
       while(head&&seti.count(head->val)){
        ListNode* tmp=head;
        head=head->next;
        delete tmp;
       } 
       if(!head) return nullptr;
       ListNode* curr=head;
       while(curr->next){
        if(seti.contains(curr->next->val)){
            ListNode* tmp=curr->next;
            curr->next=curr->next->next;
            delete tmp;
        }
        else curr=curr->next;
       }
       return head;
    }
};