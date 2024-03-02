class Solution {
public:
    string gameResult(const ListNode* const head) 
    {
        const ListNode* node = head;
        int odd_score = 0;
        int even_score = 0;
        int idx = 0;

        while (node->next != nullptr) {
            if (idx % 2 == 0) {
                const int even_val = node->val;
                const int odd_val = node->next->val;
                if (even_val > odd_val) {
                    ++even_score;
                }
                else if (even_val < odd_val) {
                    ++odd_score;
                }
            }
            ++idx;
            node = node->next;
        }
        
        if (odd_score == even_score) {
            return "Tie";
        }

        return odd_score > even_score ? "Odd" : "Even";
    }
};

// https://leetcode.com/problems/winner-of-the-linked-list-game/description/
