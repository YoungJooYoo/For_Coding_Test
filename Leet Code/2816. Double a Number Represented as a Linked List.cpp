class Solution {
public:
    // 주어진 연결 리스트를 두 배로 늘리는 함수
    ListNode* doubleIt(ListNode* head) {
        // 연결 리스트를 뒤집음
        head = reverseList(head);

        ListNode* temp = head;
        int carry = 0; // 올림 수

        while (temp != nullptr) {
            const int value = (temp->val * 2) + carry;
            temp->val = value % 10; // 현재 자리의 값 업데이트
            carry = value / 10; // 다음 자리로 올림
            if (temp->next == nullptr && carry > 0) {
                // 마지막 노드에 올림 수가 남아 있으면 새 노드 추가
                ListNode* newNode = new ListNode(carry);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }

        // 다시 연결 리스트를 뒤집음
        head = reverseList(head);
        return head;
    }

private:
    // 연결 리스트를 뒤집는 함수
    ListNode* reverseList(ListNode* const head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        
        while (cur != nullptr) {
            ListNode* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        
        return prev;
    }
};

//https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/?envType=daily-question&envId=2024-05-07
