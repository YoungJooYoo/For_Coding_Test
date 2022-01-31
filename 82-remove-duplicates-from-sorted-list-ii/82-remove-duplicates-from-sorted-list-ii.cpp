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