class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<ListNode*> result(k, nullptr);
        ListNode* current = head;
        size_t length = 0;

        while (current != nullptr) {
            ++length;
            current = current->next;
        }
        
        const int minSize = length / k;
        const int extra = length % k; // 처음 extra 개의 부분 리스트는 하나 더 많은 요소를 가짐
        
        current = head;
        for (size_t i = 0; i < k && current != nullptr; ++i) {
            result[i] = current;
            const int partSize = minSize + (i < extra ? 1 : 0);
            for (size_t j = 1; j < partSize; ++j) {
                current = current->next;
            }
            ListNode* next = current->next;
            current->next = nullptr; // 부분 리스트 분리
            current = next;
        }
        
        return result;
    }
};

// https://leetcode.com/problems/split-linked-list-in-parts/description/
