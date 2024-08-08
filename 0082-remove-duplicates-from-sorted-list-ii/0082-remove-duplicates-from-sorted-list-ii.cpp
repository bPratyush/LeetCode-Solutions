class Solution {
public:
    int findlength(ListNode* head) { 
        ListNode* curr = head; 
        int cnt = 0; 
        while (curr != NULL) { 
            cnt++; 
            curr = curr->next; 
        } 
        return cnt; 
    } 
  
    void convertArr(ListNode* head, std::vector<int>& res) { 
        ListNode* curr = head;
        while (curr != NULL) { 
            res.push_back(curr->val);
            curr = curr->next; 
        } 
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        vector<int> res;
        convertArr(head, res);
        sort(res.begin(), res.end());
        unordered_map<int,int> freq;
        for(int i=0;i<res.size();i++){
            freq[res[i]]++;
        }
        vector<int> uniqueRes;
        for (int val : res) {
            if (freq[val] == 1) {
                uniqueRes.push_back(val);
            }
        }
        ListNode* newHead = nullptr;
        ListNode* current = nullptr;

        for (int val : uniqueRes) {
            if (!newHead) {
                newHead = new ListNode(val);
                current = newHead;
            } else {
                current->next = new ListNode(val);
                current = current->next;
            }
        }

        return newHead;
    }
};
