class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<int> st1;
        stack<int> st2;
        ListNode* list1 = l1;
        ListNode* list2 = l2;
        
        // 링크드 리스트 값을 스택에 넣기
        while (list1 != nullptr) {
            st1.push(list1->val);
            list1 = list1->next;
        }
        while (list2 != nullptr) {
            st2.push(list2->val);
            list2 = list2->next;
        }
        
        int carry = 0;
        ListNode* result = nullptr;
        
        while (!st1.empty() || !st2.empty() || carry == 1) {
            int x = st1.empty() ? 0 : st1.top();
            int y = st2.empty() ? 0 : st2.top();
            int sum = x + y + carry;
            
            if (!st1.empty()) st1.pop();
            if (!st2.empty()) st2.pop();
            
            ListNode* temp = new ListNode(sum % 10);
            temp->next = result; // 새로 생성한 노드 temp를  result노드 맨 앞에 붙인다.
            result = temp; // result는 맨 앞 노드인 temp로 갱신한다.
            carry = sum / 10;
        }
        
        return result;
    }
};
