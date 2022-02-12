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

/*
풀이법 :
해시 자려구조 맵을 사용해
중복 접근이 일어나는 최초의 구간이 사이클 시작하는 인덱스인 것을 알 수 있다.
따라서 그 구간을 리턴하면 답이 된다.
*/