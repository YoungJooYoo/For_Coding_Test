class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
		vector<int> nums;
        
        if (lists.empty() == true) {
            return NULL;
        }

		for (size_t i = 0; i < lists.size(); ++i) {
			ListNode* node = lists[i];
			while (node != NULL) {
				nums.push_back(node->val);
				node = node->next;
			}
		}

		sort(nums.begin(), nums.end());
		
		ListNode* result = new ListNode; 
		ListNode* head = result;
		for (size_t i = 0; i < nums.size(); ++i) {  
			result->next = new ListNode;
            result->next->val = nums[i];
			result = result->next;
		}
        // 값이 0인 head만들고 head->next부터, 1개씩 노드 만들어가면서 val을 넣어줌
        // head에 val = 0 이 있으므로, head->next부터 merge된 노드이다.
        
		return head->next;
    }
};