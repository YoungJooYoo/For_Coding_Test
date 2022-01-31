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
            if (curr->next->val == curr->next->next->val) {
                int value = curr->next->val;
                while (curr->next != nullptr && curr->next->val == value) {
                    ListNode* temp = curr->next;
                    curr->next = curr->next->next;
                    delete(temp);
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
