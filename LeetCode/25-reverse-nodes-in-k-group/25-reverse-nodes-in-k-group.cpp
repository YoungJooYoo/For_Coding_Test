class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
		if (!head) {
			return head;
		}

		vector<int> nums;
		ListNode* curr = head;

		// 배열에 연결리스트 노드 값을 담는다.
		while (curr) {
			nums.push_back(curr->val);
			curr = curr->next;
		}

		auto itr = nums.begin();
		size_t i = 0;
		
		// k 간격만큼 배열을 reverse를 만든다.
		while (i + k <= nums.size()) {
			reverse(itr, itr + k);
			itr = itr + k;
			i = i + k;
		}
		
		curr = head;
		// 조건에 맞게 정렬된 배열의 값을 연결리스트에 복사한다.
		for (const int& num : nums) {
			curr->val = num;
			curr = curr->next;
		}
		
		return head;
    }
};