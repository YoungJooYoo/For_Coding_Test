/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* node = head;
        
        size_t check = 0;
        solution(node, check);
        
        return node; 
    }
    void solution(ListNode* head, size_t check)
    {
        ListNode* node = head;
        size_t temp = 0;
        
        if (head == NULL) {
            return;
        }
        // check하면서 짝수부에서 값변경 반복
        if (node->next != NULL && check % 2 == 0) {
            temp = node->val;
            node->val = node->next->val;
            node->next->val = temp;
        }
        solution(node->next, check + 1);
    }
};