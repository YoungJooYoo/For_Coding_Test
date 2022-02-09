class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
	{
        vector<int> nums;
		vector<int> result;
		ListNode* curr = head;

		if (curr == nullptr || curr->next == nullptr) {
			return head;
		}

		while (curr != nullptr) {
			nums.push_back(curr->val);
			curr = curr->next;
		}

		// k보다 작은 원소를 result 배열에 넣는다.
		for (const int& num : nums) {
			if (num < x) {
				result.push_back(num);
			}
		}

		// k랑 같거나 큰 원소를 넣는다. 인접한 순서가 지켜지게 된다.
		for (const int& num : nums) {
			if (num >= x) {
				result.push_back(num);
			}
		}

		curr = head;
		size_t i = 0;
		while(curr != nullptr){
            curr->val = result[i];
            curr = curr->next;
			i++;
        }

		return head;
    }
};