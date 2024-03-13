class Solution {
public:
    ListNode* frequenciesOfElements(ListNode* const head) 
    {
        ListNode* curr_node = head;
        std::map<int, int> freq;

        while (curr_node != nullptr) {
            ++freq[curr_node->val];
            curr_node = curr_node->next;
        }

        ListNode* const dummy = new ListNode();
        ListNode* result = dummy;

        for (const auto& elem : freq) {
            ListNode* const new_node = new ListNode();
            new_node->val = elem.second;
            result->next = new_node;
            result = result->next;
        }

        return dummy->next;
    }
};

// https://leetcode.com/problems/linked-list-frequency/description/
