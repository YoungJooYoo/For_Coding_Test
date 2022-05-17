class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
        vector<int> vals;
        ListNode* node = head;
        int temp;
        
        while (node != nullptr) {
            vals.push_back(node->val);
            node = node->next;
        }
        
        temp = vals[k - 1];
        vals[k - 1] = vals[vals.size() - k];
        vals[vals.size() - k] = temp;
        
        node = head;
        for (size_t i = 0; i < vals.size(); i++) {
            node->val = vals[i];
            node = node->next;
        }
        
        return head;
    }
};