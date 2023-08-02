class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        ListNode* node = head;
		vector<int> nums;

		if (node == NULL) {
			return false;
		}
		
		while (node != NULL) {
			nums.push_back(node->val);
			node = node->next;
		}
		
		int begin = 0;
		int end = nums.size() - 1;
		while (begin < end) {
			if (nums[begin] != nums[end]) {
				return false;
			}
            begin++;
            end--;
		}

		return true;
    }
};