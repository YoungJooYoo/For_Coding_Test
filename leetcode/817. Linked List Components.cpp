class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        
        unordered_map<int,int> freq ;
        int ans = 0;

        for (const auto& num : nums) {
            freq[num]++;
        }
    
        while(head != nullptr) {
            if (freq[head->val] != 0) { // 리스트에 해당 원소가 존재하지 않으면
                while (head->next != nullptr && freq[head->next->val] != 0) { // head->next->val이 존재한다면
                    head = head->next;
                }
                ans++;
            }
            head = head->next;
        }

        return ans;
    }
};

// https://leetcode.com/problems/linked-list-components/description/
