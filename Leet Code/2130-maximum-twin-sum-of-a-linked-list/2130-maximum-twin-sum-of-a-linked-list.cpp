class Solution {
public:
    int pairSum(ListNode* head) 
    {
        vector<int> vals;
        int max_sum = 0;
        
        while (head != nullptr) {
            vals.push_back(head->val);
            head = head->next;
        }
        
        const size_t ARRAY_LENGTH = vals.size();
        
        for (int i = 0; i < ARRAY_LENGTH / 2; i++) {
            max_sum = max(max_sum, vals[i] + vals[ARRAY_LENGTH - 1 - i]);
        }
        
        return max_sum;
    }
};

/*
풀이법 :

링크드리스트의 값에서
1 2 3 4 5 6 7 8

끝에서 부터 인덱스를
1 8 
2 7
3 6
4 6
이렇게 짝을 이루면서, 최대 값의 합이 무엇인지 묻는 것

*/