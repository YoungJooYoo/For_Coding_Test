class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) 
    {
        unordered_map<int, int> freq;
        ListNode* current = head;
        
        while (current != nullptr) {
            ++freq[current->val];
            current = current->next;
        }

        ListNode* result = new ListNode;
        ListNode* temp = result;
        current = head;
        while (current != nullptr) {
            if (freq[current->val] == 1) { // 중복 없는 값만 추가
                temp->next = new ListNode(current->val);
                temp = temp->next;
            }
            current = current->next;
        }

        return result->next;
    }
};

// https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/description/
