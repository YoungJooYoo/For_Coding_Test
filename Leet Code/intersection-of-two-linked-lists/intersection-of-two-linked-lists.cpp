/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* node_A = headA;
        ListNode* node_B = headB;
        
        // headA를 순차적으로 넘기면서, headB의 처음부터 끝까지 반복비교
        // headA와 headB와 같은 주소를 가르키는 시점이 있다면 return.
        while (node_A != nullptr) {
            node_B = headB;
            while (node_B != nullptr) {
                if (node_A == node_B) {
                    return node_B;
                }
                node_B = node_B->next;
            }
            node_A = node_A->next;
        }
        
        return nullptr;
    }
};

/* 
풀이법 : Brute Force
*/