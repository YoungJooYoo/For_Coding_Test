class Solution {
public:
    Node* insert(Node* head, int insertVal) 
    {
        if (head == nullptr) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        
        Node* curr = head;
        Node* next = curr->next;
        
        while (curr->next != nullptr && next != head) {
            // curr->val < insertVal < next->val 인경우
            if (curr->val < insertVal && insertVal <= next->val) {
                break;
            }
            // 리스트의 최대값과 최소값 경계 사이의 값이 들어온 경우
            if (curr->val > next->val && (insertVal >= curr->val || next->val >= insertVal)) {
                break;
            }
            curr = curr->next;
            next = next->next;
        }
        
        curr->next = new Node(insertVal, next);
    
        return head;
    }
};