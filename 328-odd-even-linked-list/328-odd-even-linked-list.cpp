class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if (head == nullptr) {
            return nullptr;
        }
        
        vector<int> odd_index; // 홀수인덱스 값 저장 배열
        vector<int> even_index; // 짝수 저장 인덱스 값 저장 배열
        ListNode* curr = head;
        size_t i = 0;
        
        // 짝수인덱스 홀수인덱스 따로 구분하면서 배열에 값을 저장한다.
        while (curr != nullptr) {
            if (i % 2 == 0) { // 짝수인덱스
                even_index.push_back(curr->val);
            }
            else { // 홀수인덱스 경우
                odd_index.push_back(curr->val);
            }
            curr = curr->next;
            i++;
        }
        
        // 문제에서 요구하듯 짝수인덱스 먼저 리스트에 넣고, 그 다음 홀수 인덱스 값을 이어서 넣는다.
        curr = head;
        
        for (size_t i = 0; i < even_index.size(); i++) {
            curr->val = even_index[i];
            curr = curr->next;
        }
        for (size_t i = 0; i < odd_index.size(); i++) {
            curr->val = odd_index[i];
            curr = curr->next;
        }
        
        return head;
    }
};

/*
풀이법 :
짝수, 홀수 인덱스를 구분해서 배열에 담는다.
배열에 담긴 값을 리스트를 순회하면서 짝수 먼저 넣고, 홀수먼저 넣는다.
*/