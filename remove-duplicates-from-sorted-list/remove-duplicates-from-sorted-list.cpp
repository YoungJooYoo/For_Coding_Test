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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* node = head;
        
        while (node != NULL && node->next != NULL) {
            if (node->val == node->next->val) {
                node->next = node->next->next;
            }
            else {
                node = node->next; // 다음노드로 이동
            }
        }
        
        return head; // 완성된 노드들의 시작점인 head 반환
    }
};