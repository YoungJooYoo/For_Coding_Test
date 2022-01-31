class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return head;
        }
        ListNode * temp = head;
        ListNode * prev = new ListNode;
        ListNode * head1 = prev;
        prev->next = head;
        int find = head->val;
        
        while (temp != NULL) {
            if (temp != NULL and temp->next != NULL and temp->val == temp->next->val) {
                while (temp != NULL and temp->next != NULL and temp->val == temp->next->val) {
                    temp = temp->next;
                }
                prev->next = temp->next;
                temp = prev->next;
            }
            else {
                prev = prev->next;
                temp = temp->next;
                
            }
        }
        
        return head1->next;
    }
};