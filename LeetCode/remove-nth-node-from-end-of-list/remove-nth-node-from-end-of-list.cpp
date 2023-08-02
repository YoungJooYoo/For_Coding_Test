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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        ListNode* prev = NULL;
        size_t node_count = 1;
        size_t count = 0;
        size_t node_target_index;
        
        while (current != NULL) {
            node_count++;
            current = current->next;
        }
    
        node_target_index = node_count - n; // 삭제할 노드 위치
        current = head;
        
        while(current != NULL) {
            if (node_target_index == 1) {
                return head->next; // 맨 앞읠 빼는 경우 다음 노드부터 반환
            }
            else {
                count++; // count 즈가시키면서 삭제할 노드 위치 찾기
                if (count == node_target_index - 1) { // 삭제할 노드 이전에서 작업을 시행한다.
                    current->next = current->next->next;
                }
            }
            prev=current;
            current=current->next;
        }
        
        return head;
    }
};