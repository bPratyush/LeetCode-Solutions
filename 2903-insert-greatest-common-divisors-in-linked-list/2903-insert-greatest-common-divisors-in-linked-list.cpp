class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* node1 = head;
        ListNode* node2 = head->next;
        while (node2) {
            int gcdValue = gcd(node1->val, node2->val);
            ListNode* gcdNode = new ListNode(gcdValue);
            node1->next = gcdNode;
            gcdNode->next = node2;
            node1 = node2;
            node2 = node2->next;
        }
        return head;  
    }
};
