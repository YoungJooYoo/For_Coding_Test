class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> valuesToKeep; // 유지할 값들을 저장할 벡터
        ListNode* current = head; // 현재 노드를 가리키는 포인터

        // 리스트를 순회하면서 유지할 값들 결정
        while (current != nullptr) {
            // 현재 노드의 값이 스택의 마지막 값보다 크면 더 작은 값들 제거
            while (!valuesToKeep.empty() && valuesToKeep.back() < current->val) {
                valuesToKeep.pop_back();
            }
            // 현재 노드의 값을 스택에 추가
            valuesToKeep.push_back(current->val);
            current = current->next;
        }

        // 리스트를 다시 순회하면서 노드 값을 업데이트
        ListNode* newTail = head; // 새로운 리스트의 꼬리 노드
        current = head; // 다시 처음부터 순회
        for (int val : valuesToKeep) {
            current->val = val; // 값을 업데이트
            newTail = current;   // 꼬리 노드를 업데이트
            current = current->next;
        }

        newTail->next = nullptr; // 꼬리 노드의 다음을 null로 설정
        return head; // 수정된 리스트의 head 반환
    }
};

// https://leetcode.com/problems/remove-nodes-from-linked-list/description/
