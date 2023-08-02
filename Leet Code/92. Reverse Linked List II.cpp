class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        vector<int> nums;
        ListNode* node = head;
        size_t idx = 1;

        while (node != nullptr) {
            if (left <= idx && idx <= right) {
                nums.push_back(node->val);
            }
            ++idx;
            node = node->next;
        }

        reverse(nums.begin(), nums.end());

        node = head;
        idx= 1;
        int i = 0;
        while (node != nullptr) {
            if (left <= idx && idx <= right) {
                node->val = nums[i++];
            }
            ++idx;
            node = node->next;
        }

        return head;    
    }
};

// https://leetcode.com/problems/reverse-linked-list-ii/description/
