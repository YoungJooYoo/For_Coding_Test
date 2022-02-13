class Solution {
public:
    Node* flatten(Node* head) 
    {
        Node* next;
        Node* p;
        
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            if (curr->child) { // child node에 다음 노드가 있는지 먼저 찾는다.
                next = curr->next; //  child하고 이어지기전 next를 저장
                curr->next = curr->child; // child를 next로 변경
                curr->next->prev = curr; // curr->next = child와 연결 되어 있으므로 child의 prev를 curr과 연결
                curr->child = NULL; // 연결 작업 끝나면 child를 끊어준다.
                p = curr->next; // curr->next => child와 연결된 후 child 노드로 이동
                
                while (p->next) {
                    p = p->next; // child 연결 이후, nullptr나올떄까지 이동
                }
                
                p->next = next; // 아까 저장해둔 child와 이어지기전 next를 연결
                
                if (next) { // 2중연결 리스트므로, 위에서 next연결했으므로 prev연결
                    next->prev = p;
                }
            }
        }
        
	    return head;
    }
};