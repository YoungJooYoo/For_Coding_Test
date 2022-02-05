class Solution {
public:
    void reorderList(ListNode* head) 
    {
        vector<int> nums;
        ListNode* curr = head->next;
        
        while (curr != nullptr) {
            nums.push_back(curr->val);
            curr = curr->next;
        }
        
        curr = head->next;
        size_t i = 0;
        size_t j = nums.size() - 1;
        
        while (curr != nullptr && i <= j) {
            curr->val = nums[j];
            curr = curr->next;
            if (curr == nullptr) break;
            assert(curr != nullptr);
            
            curr->val = nums[i];
            curr = curr->next;
            i++;
            j--;
        }
        
        return;
    }
};