class Solution{
public:
    void copylist(Node* head){
        Node* tmp=head;
        Node* n=head->next;
        while(tmp){
            Node* copy=new Node(tmp->val);
            tmp->next=copy;
            copy->next=n;
            tmp=n;
            if(n!=NULL) n=n->next;
        }
    }
    void handlerandom(Node* head){
        Node* tmp=head;
        while(tmp){
            if(tmp->random) tmp->next->random=tmp->random->next;
            tmp=tmp->next->next;
        }
    }
    Node* detach(Node* head){
        Node* dummy=new Node(-1);
        Node* tail=dummy,*tmp=head;
        while(tmp){
            tail->next=tmp->next;
            tail=tail->next;
            tmp->next=tail->next;
            tmp=tmp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList (Node* head){
        if(!head) return NULL;
        copylist(head);
        handlerandom(head);
        return detach(head);
    }
};