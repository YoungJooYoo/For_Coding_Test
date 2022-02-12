class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
	{
        ListNode* curr = head;
		vector<int> nums;

		if (curr == nullptr) {
			return nullptr;
		}
		
		// 연결리스트의 값을 배열로 이동
		while (curr != nullptr) {
			nums.push_back(curr->val);
			curr = curr->next;
		}

		k = k % nums.size(); // k의 회전횟수 0~k사이사 나올 수 있게
		size_t start = nums.size() - k;
		size_t end = start + k;
		curr = head;

		/* 로테이트 되는 부분 먼저 넣기 */
		while (start < end) {
			curr->val = nums[start];
			curr = curr->next;
			start++;
		}

		/* 로테이트 이후 부분 넣기 */
		start = 0;
		end = nums.size() - k;
		while (start < end) {
			curr->val = nums[start];
			curr = curr->next;
			start++;
		}

		return head;
    }
};