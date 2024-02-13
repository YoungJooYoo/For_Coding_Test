class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* const head) 
    {
        // 더미 노드를 생성하여 연결 리스트의 시작 부분에 추가합니다.
        // 이렇게 하면 헤드를 조작할 때 발생할 수 있는 문제를 방지할 수 있습니다.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // 해시맵을 사용하여 각 누적 합에 대한 마지막 노드를 저장합니다.
        unordered_map<int, ListNode*> prefixSumMap;
        
        int sum = 0; // 누적 합을 저장할 변수입니다.
        // 연결 리스트를 순회하면서 각 노드까지의 누적 합을 계산합니다.
        for (ListNode* node = dummy; node != nullptr; node = node->next) {
            sum += node->val;
            // 현재 누적 합과 해당 노드를 해시맵에 저장합니다.
            prefixSumMap[sum] = node;
        }
        
        sum = 0; // 누적 합을 다시 0으로 초기화합니다.
        // 다시 연결 리스트를 순회하면서 각 노드를 처리합니다.
        for (ListNode* node = dummy; node != nullptr; node = node->next) {
            sum += node->val;
            // 현재 누적 합에 대응하는 마지막 노드를 해시맵에서 찾습니다.
            // 그리고 현재 노드의 다음 노드를 그 노드의 다음 노드로 설정합니다.
            // 이 과정에서 합이 0이 되는 노드들이 리스트에서 제거됩니다.
            node->next = prefixSumMap[sum]->next;
        }
        
        // 수정된 연결 리스트의 헤드를 반환합니다.
        ListNode* result = dummy->next;
        delete dummy; // 더미 노드는 더 이상 필요 없으므로 메모리를 해제합니다.
        return result;
    }
};

// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/
