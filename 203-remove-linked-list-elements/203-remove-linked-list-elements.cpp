class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
	{
        if (head == NULL) {
            return head;
        }

        ListNode* node = head;
		ListNode* temp;

        while (node->next != NULL) {
            if (node->next->val == val) {
				temp = node->next;
                node->next = node->next->next;
				delete(temp);
            }
            else {
                node = node->next;
            }
        }

		// head 값은 제외하고, val제거 했으므로 마지막 head->val검사
        if (head->val == val) {
			head = head->next;
		}
    
        return head;
    }
};