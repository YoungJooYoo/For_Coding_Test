/*
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if(head != nullptr) {
            return head;
        }
        
        ListNode* prev_node = nullptr;
        ListNode* curr_node = head; 
        ListNode* next_node = curr_node->next;
        
        while (next_node != nullptr) {
            if (curr_node->val == next_node->val) {
                while(next_node && next_node->val == curr_node->val)
                    next_node = next_node->next;
                if(prev_node == nullptr) // This condition means element at the head is repeating. So, head pointer needs to be shifted.
                    head = next_node;
                else
                    prev_node->next = next_node;
            }
            else {
                prev_node = curr_node;
            }
            curr_node = next_node;
            if (next_node != nullptr) {
                next_node = curr_node->next;
            }
        }
        
        return head;
    }
}; 
*/

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if(!head)
            return head;
        
        ListNode *prev=NULL, *curr=head, *next=curr->next;
        while(next)
        {
            if(curr->val == next->val)
            {
                while(next && next->val == curr->val)
                    next=next->next;
                if(!prev) // This condition means element at the head is repeating. So, head pointer needs to be shifted.
                    head=next;
                else
                    prev->next = next;
            }
            else
            {
                prev=curr;
            }
            
            curr=next;
            if(next)
                next=curr->next;
        }
        return head;
    }
};