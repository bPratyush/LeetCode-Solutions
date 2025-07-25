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
        vector<int>res;
        for(ListNode* ls:lists){
            while(ls){
                res.push_back(ls->val);
                ls=ls->next;
            }
        }
        sort(res.begin(),res.end());
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        for(int val:res){
            curr->next=new ListNode(val);
            curr=curr->next;
        }
        return dummy->next;
    }
};