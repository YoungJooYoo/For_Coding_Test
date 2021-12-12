/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* current_node = head;
        Node* ans_node = nullptr;
        Node* temp_node = nullptr;
        
        if (head == nullptr) {
            return nullptr;
        }
        
        // 기존 노드에서 새로운 노드를 deep copy.
        while (current_node != nullptr) {
            temp_node = new Node(current_node->val, current_node->next, nullptr);
            current_node->next = temp_node;
            current_node = temp_node->next;
        }
        
        current_node = head; // 노드를 다시 출발 지점으로 돌린다.
        
        while (current_node != nullptr) {
            temp_node = current_node->next;
            if (current_node->random != nullptr) {
                temp_node->random = current_node->random->next;
            }
            current_node = temp_node ->next;
        }
        
        current_node = head;
        ans_node = head->next;
        
        while (current_node != nullptr) {
            temp_node = current_node->next;
            current_node->next = temp_node->next;
            current_node = current_node->next;
            if (current_node != nullptr) {
                temp_node->next = current_node->next;
            }
        }
        
        return ans_node;
    }
};