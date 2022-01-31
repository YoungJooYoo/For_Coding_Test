class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* cur = dummy;
        int duplicate;
        
        while (cur->next != nullptr && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                duplicate = cur->next->val;
                while (cur->next != nullptr && cur->next->val == duplicate) {
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;
            }
        }
        
        return dummy->next;
    }
};