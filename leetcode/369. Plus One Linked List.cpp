class Solution {
 public:
  auto plusOne(ListNode *head) -> ListNode * {
    ListNode* last_not_nine = nullptr;
    auto* curr = head;

    while (curr) {
      if (curr->val < 9) { // 9가 아니면 탐색 진행 
        last_not_nine = curr;
      }

      curr = curr->next;
    }

    ListNode* after_not_nine = nullptr;
    if (last_not_nine != nullptr) {
      ++last_not_nine->val; // 9로 끝난 숫자가 아니면 그냥 더한다.
      after_not_nine = last_not_nine->next;
    } else { // 9라면 1더하면 캐리발생 + 자리수 하나 늘려야한다. head 앞에 1을 추가한다.
      auto *new_head = new ListNode(1);
      new_head->next = head;
      after_not_nine = head;
      head = new_head;
    }

    while (after_not_nine != nullptr) {
      after_not_nine->val = 0; // 9자리 0으로 만듬
      after_not_nine = after_not_nine->next;
    }

    return head;
  }
};

// https://leetcode.com/problems/plus-one-linked-list/description/
