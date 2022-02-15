class Solution {
public:
    ListNode* sortList(ListNode* head) 
	{
        ListNode* curr = head;
		ListNode* temp;
		vector<int> nums;

		while (curr != nullptr) {
			temp = curr;
			nums.push_back(curr->val);
			curr = curr->next;
			delete temp;
		}

		sort(nums.begin(), nums.end());
		ListNode* ans = new ListNode;
		temp = ans;
        
		for (size_t i = 0; i < nums.size(); i++) {
			temp->next = new ListNode;
			temp->next->val = nums[i];
			temp = temp->next;
		}

		return ans->next;
    }
};