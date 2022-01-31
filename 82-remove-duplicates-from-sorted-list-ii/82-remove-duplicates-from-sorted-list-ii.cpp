class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == NULL) {
            return head;
        }
            
        ListNode* ans_head = new ListNode;
        ans_head->next = head;
        ListNode* curr = ans_head;
        
        while (curr->next != nullptr && curr->next->next != nullptr) {
            if (curr->next->val == curr->next->next->val) { // 문제에서 원하는 조건, 이전노드와 다음노드의 value 가 같은경우
                int duplicate_value = curr->next->val; // 중복된 값이 나오는 최초 지점을 미리 저장한다.
                while (curr->next != nullptr && curr->next->val == duplicate_value) {
                    ListNode* temp = curr->next; // 필요없는 노드를 삭제하기 위한 변수
                    curr->next = curr->next->next; // 계속 노드의 다음다음으로 이동한다.
                    delete(temp); // 중복되는 값을 가진 노드는 삭제한다.
                }
            }   
            else { // val값이 서로 같지 않다면 그냥 다음 노르도 이동
                curr = curr->next; 
            }
        }

        return ans_head->next;
    }
};

/*
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (head == NULL or head->next == NULL) {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* prev = new ListNode;
        ListNode* ans_head = prev;
        
        prev->next = head;
        int find = head->val;
        
        while (curr != NULL) {
            if (curr != NULL and curr->next != NULL and curr->val == curr->next->val) {
                while (curr != NULL and curr->next != NULL and curr->val == curr->next->val) {
                    curr = curr->next;
                }
                prev->next = curr->next;
                curr = prev->next;
            }
            else {
                prev = prev->next;
                curr = curr->next;
                
            }
        }
        
        return ans_head->next;
    }
};
*/
