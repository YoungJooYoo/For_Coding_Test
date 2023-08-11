class Solution {
public:
    int get_gcd(int a, int b)
    {
        int max_div = 1;	// 가장 큰 공약수를 저장할 변수
        int range = min(a, b); 	// 두 수 중 작은 값까지만 조사

        // i부터 공약수를 찾는다.
        for (int i = 1; i <= range; i++) { 
            // 두 수 모두의 약수일 경우
            if (a % i == 0 && b % i == 0) { 
                max_div = i; 	// 갱신 (i는 점점 증가하므로 range 끝까지 수행)
            }
        }
        
        return max_div;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        ListNode* curr = head;
        ListNode* next = head->next;

        while (curr != nullptr && next != nullptr) {
            int div = get_gcd(curr->val, next->val);
            ListNode* node = new ListNode(div);
            curr->next = node;
            node->next = next;
            curr = next;
            next = next->next;
        }

        return head;
    }
};

// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/
