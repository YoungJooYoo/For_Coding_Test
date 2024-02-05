class Solution {
public:
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode* current = head;
        ListNode* next = current->next;

        while (is_list_sorted(current, next) != true) { }
        return head;
    }
    
private: 
    bool is_list_sorted(ListNode* current, ListNode* next) 
    {
        bool is_sorted = true;

        while (next != nullptr) {
            
            if (current->val > next->val) {
                swap(current->val, next->val);
                is_sorted = false;
            }
            current = current->next;
            next = next->next;
        }

        return is_sorted;
    }
};

// https://leetcode.com/problems/insertion-sort-list/description/
