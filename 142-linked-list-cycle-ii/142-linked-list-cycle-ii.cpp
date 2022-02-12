/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) 
    {
        ListNode* curr = head;
        unordered_map<ListNode*, int> mp;
            
        while (curr != nullptr) {
            mp[curr]++;
            if (mp[curr] > 1) {
                return curr;
            }
            curr = curr->next;
        }
        
        return nullptr;
    }
};