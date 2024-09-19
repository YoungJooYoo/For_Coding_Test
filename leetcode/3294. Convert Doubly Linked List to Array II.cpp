class Solution {
public:
    vector<int> toArray(const Node* node) 
    {
        const Node* head = node;
        vector<int> result;

        if (node == nullptr) 
        {
            return result;
        } 

        // 리스트의 시작(head)까지 이동
        while (head->prev != nullptr) 
        {
            head = head->prev;
        }

        // 리스트의 시작부터 끝까지 순차적으로 값 수집
        const Node* current = head;
        while (current != nullptr) 
        {
            result.push_back(current->val);
            current = current->next;
        }

        return result;
    }
};

// https://leetcode.com/problems/convert-doubly-linked-list-to-array-ii/description/
