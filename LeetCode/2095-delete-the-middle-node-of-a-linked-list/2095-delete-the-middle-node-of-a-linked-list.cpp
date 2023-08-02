class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        if (head->next == nullptr) {
            return nullptr;
        }
            
        auto slow = head;
        auto fast = head->next->next;
        
        // slow가 멈추는 위치가 중간위치
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
    }
};

/*
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        ListNode* node = head;
        size_t list_length = 0;
        
        while (node != nullptr) {
            node = node->next;
            list_length++;
        }
        
        if (list_length == 0 || list_length ==1) {
            return nullptr;
        }
        
        size_t mid_index = list_length / 2;
        node = head;
        
        int count = 0;
        while (node != nullptr && count != mid_index - 1) {
            node = node->next;
            count++;
        }
        
        node->next = node->next->next;
        
        return head;
    }
};
*/