class Solution {
public:
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode* result = new ListNode(0);
        ListNode* node = result;
        int temp = 0;

        head = head->next;

        while (head != nullptr) {
            if (head->val != 0) {
                temp += head->val;
            }
            else {
                node->next = new ListNode(temp);
                node = node->next;
                temp = 0;
            }
            head = head->next;
        }

        return result->next;
    }
};

// https://leetcode.com/problems/merge-nodes-in-between-zeros/description/
