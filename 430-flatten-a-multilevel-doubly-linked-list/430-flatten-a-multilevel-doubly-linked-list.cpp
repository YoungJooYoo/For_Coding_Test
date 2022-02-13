class Solution {
public:
    Node* flatten(Node* head) 
    {
        Node* next;
        Node* p;
        
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            if (curr->child) { // child node에 다음 노드가 있는지 먼저 찾는다.
                next = curr->next; // 
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = NULL;
                p = curr->next;
                
                while (p->next) {
                    p = p->next;
                }
                
                p->next = next;
                
                if (next) {
                    next->prev = p;
                }
            }
        }
        
	    return head;
    }
};