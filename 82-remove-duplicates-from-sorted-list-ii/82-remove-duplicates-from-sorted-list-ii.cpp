class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == NULL) {
            return head;
        }
            
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        
        while (cur->next && cur->next->next) {
            if(cur->next->val==cur->next->next->val) {
                int d = cur->next->val;
                while (cur->next && cur->next->val==d) {
                    ListNode* temp = cur->next;
                    cur->next = cur->next->next;
                    delete(temp);
                }
            }   
            else {
                cur = cur->next; 
            }
        }

        return dummy->next;
    }
};

/*
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (head == NULL or head->next == NULL) {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* prev = new ListNode;
        ListNode* ans_head = prev;
        
        prev->next = head;
        int find = head->val;
        
        while (curr != NULL) {
            if (curr != NULL and curr->next != NULL and curr->val == curr->next->val) {
                while (curr != NULL and curr->next != NULL and curr->val == curr->next->val) {
                    curr = curr->next;
                }
                prev->next = curr->next;
                curr = prev->next;
            }
            else {
                prev = prev->next;
                curr = curr->next;
                
            }
        }
        
        return ans_head->next;
    }
};
*/
