/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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