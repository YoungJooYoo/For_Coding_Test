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
    ListNode* reverseList(ListNode* head) {
        ListNode* previous_node = NULL;
		ListNode* current_node = head;
        ListNode* next_node = NULL;
        
        // 노드 교환을 반복
        while(current_node != NULL) {
            next_node = current_node->next; // 다음노드 저장
        	current_node->next = previous_node; // 이전 노드를 현재 노드로
        	previous_node = current_node; // 현재 노드를, 이전 노드로
        	current_node = next_node; // 다음 노드를, 현재노드로
        }
        
		return previous_node;
    }
};