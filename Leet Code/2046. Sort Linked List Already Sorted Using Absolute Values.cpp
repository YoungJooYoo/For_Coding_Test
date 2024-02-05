class Solution {
public:
    ListNode* sortLinkedList(ListNode* head) 
    {
        vector<int> nums;
        ListNode* current = head;

        while (current != nullptr) {
            nums.push_back(current->val);
            current = current->next;
        }
        sort(nums.begin(), nums.end());

        int idx = 0;
        current = head;
        while (current != nullptr) {
            current->val = nums[idx++];
            current = current->next;
        }

        return head;
    }
};

// https://leetcode.com/problems/sort-linked-list-already-sorted-using-absolute-values/description/
