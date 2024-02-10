class Solution {
public:
    vector<int> nextLargerNodes(ListNode* const head) 
    {
        vector<int> values; // 링크드 리스트의 값을 저장할 벡터
        for (ListNode* node = head; node != nullptr; node = node->next) {
            values.push_back(node->val); // 링크드 리스트를 순회하면서 값을 벡터에 저장
        }
        
        int n = values.size(); // 링크드 리스트의 노드 개수
        vector<int> result(n, 0); // 각 노드의 "다음으로 큰 노드"의 값을 저장할 벡터, 초기값은 0
        stack<int> st; // 노드의 인덱스를 저장할 스택

        for (int i = 0; i < n; ++i) {
            // 현재 노드의 값보다 큰 값을 가진 노드를 스택에서 찾음
            while (!st.empty() && values[st.top()] < values[i]) {
                result[st.top()] = values[i]; // 스택 상단의 노드에 대해 "다음으로 큰 노드"를 찾았으면 결과 벡터에 저장
                st.pop(); // 처리된 노드를 스택에서 제거
            }
            st.push(i); // 현재 노드의 인덱스를 스택에 추가
        }
        
        return result; // 각 노드의 "다음으로 큰 노드"의 값들이 저장된 결과 벡터 반환
    }
};

// https://leetcode.com/problems/next-greater-node-in-linked-list/description/
