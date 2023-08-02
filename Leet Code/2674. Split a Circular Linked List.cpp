class Solution {
public:
    vector<ListNode*> splitCircularLinkedList(ListNode* list) 
    {
        ListNode* slow = list;
        ListNode* fast = list;

        // 링크드리스트 ceil과 second_half 위치 구하기, 원령 리스트이므로 다음과 같이 가능하다
        while (fast->next != list && fast->next->next != list) {
            slow = slow->next; 
            fast = fast->next->next; 
        }

        // 중간지점
        const auto mid = slow->next;

        // 원형 리스트 나누기
        (fast->next == list ? fast : fast->next)->next = mid;
        slow->next = list;

        return {list, mid};
    }
};

// https://leetcode.com/problems/split-a-circular-linked-list/description/
