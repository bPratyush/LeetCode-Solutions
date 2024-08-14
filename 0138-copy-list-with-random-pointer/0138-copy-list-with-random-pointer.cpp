class Solution{
public:
    Node* copyRandomList (Node* head){
        map<Node*, Node*> oldToCopy;
        oldToCopy[NULL] = NULL;

        Node* cur = head;
        while (cur != NULL) {
            Node* copy = new Node(cur->val);
            oldToCopy[cur] = copy;
            cur = cur->next;
        }

        cur = head;
        while (cur != NULL) {
            Node* copy = oldToCopy[cur];
            copy->next = oldToCopy[cur->next];
            copy->random = oldToCopy[cur->random];
            cur = cur->next;
        }

        return oldToCopy[head];
    }
};