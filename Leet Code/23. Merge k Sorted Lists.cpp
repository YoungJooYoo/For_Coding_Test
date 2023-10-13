class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<int, vector<int>, greater<int>> q;
        ListNode* result = new ListNode(-1);
        ListNode* temp = result;

        for (auto& list : lists) {
            while (list != nullptr) {
                q.push(list->val);
                list = list->next;
            }
        }

        while (q.empty() == false) {
            temp->next = new ListNode;
            temp->next->val = q.top();
            q.pop();
            temp = temp->next;
        }

        return result->next;    
    }
};

// https://leetcode.com/problems/merge-k-sorted-lists/description/
