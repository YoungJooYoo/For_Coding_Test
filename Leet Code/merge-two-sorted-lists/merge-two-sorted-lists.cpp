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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        // 복사본 만들어서 사용하기
        ListNode* L1 = l1;
        ListNode* L2 = l2;

        // 입력부 예외처리 and 재귀함수 종료조건 next가 null이면 l1이라면 l2를 마지막으로 return
        if (l1 == NULL) {
            cout << "종료조건 L1 == NULL" << endl;
            return l2;
        }
        else if (l2 == NULL){
            cout << "종료조건 L2 == NULL" << endl;
            return l1;
        }

        // 재귀함수 방식 : 재귀콜이 스택에 쌓이면, 맨위의 스택에 쌓인 것 부터 완료되면서,
        // testcase 4-> 4 ->3->2->1->1 순서대로 역순으로 L1->next, L2->next가 연결이 된다.
        // L1, L2 val 비교, val 1이 작거나 같으면 L1 다음원소랑 L2 비교
        if (L1->val <= L2->val) {
            ListNode* nextNode = mergeTwoLists(L1->next, L2);
            cout << "L1 반환  val : " << nextNode->val << "  " << nextNode->next << endl;  
            L1->next = nextNode;
            return L1;
        }
        else { // L1, L2 val 비교, val 1이 작거나 같으면 L2 다음원소랑 L1 비교
            ListNode* nextNode = mergeTwoLists(L1, L2->next);
            cout << "L2 반환  val : " << nextNode->val << "  " << nextNode->next << endl;  
            L2->next = nextNode;
            return L2;
        }

    }
};