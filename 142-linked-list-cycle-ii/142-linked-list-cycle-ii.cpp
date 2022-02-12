class Solution {
public:
    // Space complexity: O(1).
    // Floyd's cycle-detection algorithm (tortoise and hare)
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (fast == slow) {
                // Find meeting point where cycle begins
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                
                return slow;
            }
        }

        return nullptr;       
    }
};