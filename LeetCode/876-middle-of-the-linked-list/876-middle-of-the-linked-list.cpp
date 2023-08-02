class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* slow;
        ListNode* fast;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};