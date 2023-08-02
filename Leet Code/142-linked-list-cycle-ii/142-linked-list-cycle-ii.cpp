class Solution {
public:
    // Space complexity: O(1).
    // Floyd's cycle-detection algorithm (tortoise and hare)
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // fast와 slow가 만나는 지점을 찾고
        // 그 지점에서 한칸씩 앞으로 보낸 후, 다시 만나는 지점을 찾으면 그게 답이 된다.
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (fast == slow) {
                slow = head; // slow를 돌려두는게 알고리즘 핵심 meeting point where cycle begins
                while (slow != fast) { // 다시 만나는 지점의 다음 지점이 최초 순환되는 방향이다.
                    slow = slow->next;
                    fast = fast->next;
                }
                
                return slow; // slow or fast 두개다 맞다
            }
        }

        return nullptr;       
    }
};

/*
풀이법 :
해시말고도 특별한 알고맂므으로 풀 수 있다.
Floyd's tortoise and hare -> 이 알고리즘

알고리즘참조 사이트 
https://eazymean.tistory.com/101?category=836844
*/