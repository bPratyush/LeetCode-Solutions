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
    vector<int> LLtoarr(ListNode* head){
        vector<int> res;
        ListNode* tmp=head;
        while(tmp){
            res.push_back(tmp->val);
            tmp=tmp->next;
        }
        return res;
    }
    vector<int> rotateright(vector<int>&arr,int k){
        if(arr.size()==0) return {};
        int n=arr.size();
        k%=n;
        vector<int> narr(n);
        for(int i=0;i<n;i++){
            narr[(i+k)%n]=arr[i];
        }
        return narr;
    }
    ListNode* arrtoLL(vector<int> res){
        if (res.empty()) return nullptr; 
    ListNode* head = new ListNode(res[0]); 
    ListNode* current = head; 
    for (int i = 1; i < res.size(); i++) {
        current->next = new ListNode(res[i]);  
        current = current->next; 
    }
    return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
      vector<int>arr=LLtoarr(head);
      vector<int>res=rotateright(arr,k);
      return arrtoLL(res);
    }
};