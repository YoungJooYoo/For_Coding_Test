class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) 
    {
        ListNode* node = new ListNode(0, head); // head가 시작점이니, 그 이전 노드 하나 붙여서 시작
        ListNode* temp = node;
        
        while (temp != nullptr) {
            for (size_t i = 0; i < m; ++i) {
                temp = temp->next;
                if (temp == nullptr) return head;
            }
            for (size_t i = 0; i < n; ++i) {
                if (temp->next == nullptr) return head;
                temp->next = temp->next->next;
            }
        }

        return head;
    }
};

// https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/description/
