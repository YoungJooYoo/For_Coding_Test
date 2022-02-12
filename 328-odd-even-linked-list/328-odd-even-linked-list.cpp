class Solution {
public:
        ListNode* oddEvenList(ListNode* head) 
    {
        if(!head) return head;
        ListNode *odd=head, *evenhead=head->next, *even = evenhead;
        while(even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};

/*
풀이법 :
짝수, 홀수 인덱스를 구분해서 배열에 담는다.
배열에 담긴 값을 리스트를 순회하면서 짝수 먼저 넣고, 홀수먼저 넣는다.
*/