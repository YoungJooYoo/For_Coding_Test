class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, const int a, const int b, ListNode* list2) 
    {
        ListNode* node1 = list1;

        ListNode* list_1_start = list1;
        ListNode* list_1_end = list1;

        ListNode* list_2_end = list2;;
        ListNode* remove_node = nullptr;

        // list_1_start 시작지점 전단계
        size_t count = 0;
        while (count++ != a - 1) {
            list_1_start = list_1_start->next;
        }
        remove_node = list_1_start->next; // 삭제할 a지점 저장

        // list_1_end 끝지점 찾기
        count = 0;
        while (count++ != b) {
            list_1_end = list_1_end->next;
        }

        // list_2_end 끝지점  보내기
        while (list_2_end->next != nullptr) {
            list_2_end = list_2_end->next;
        }
        
        // 첫번째지점과 list2연결
        list_1_start->next = list2;
        // list2와 끝지점 연결
         list_2_end->next = list_1_end->next;

        // remove node
        list_1_end->next = nullptr; // b지점 뒤에 가르키는 노드 끊어버리기.
        while (remove_node != nullptr) {
            ListNode* temp = remove_node;
            remove_node = remove_node->next;
            delete temp;
        }

        return list1;
    }
};

// https://leetcode.com/problems/merge-in-between-linked-lists/description/
