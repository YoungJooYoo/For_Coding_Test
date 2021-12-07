class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0); // head node
        ListNode* curr = ans;
        int carry = 0;
        
        // l1 + l2를 carry에 모아둔다.
        while(l1 != NULL || l2 != NULL || carry != 0) {
            if(l1 != NULL) {
                carry = carry + l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                carry = carry + l2->val;
                l2 = l2->next;
            }
            
            // head의 next부터 노드를 만들면서
            // 값들을 하나씩 저장한다.
            curr->next = new ListNode(carry % 10);
            carry = carry / 10;
            curr = curr->next;
        }
        
        return ans->next; // head의 다음 노드부터 반환한다.
    }
};