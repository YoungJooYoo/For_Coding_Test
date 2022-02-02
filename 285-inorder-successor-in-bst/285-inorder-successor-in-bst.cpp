class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        TreeNode* candidate = nullptr;
        TreeNode* curr = root;
        
        /* BST는 크기에 따라 이미 좌우로 정렬 되있으므로, 
        p->val 값이 root의 기준보다 크고 작은지에 따라 오른쪽 왼쪽으로 경로를 나누어준다 */
        while (curr != nullptr) {
            if (p->val < curr->val) {
              candidate = curr; // 타겟은 중위후속자를 찾는 것이므로 왼쪽을 탐색하다가 나오면 답이된다.
              curr = curr->left;
            } 
            else { // p->val >= curr->val
              curr = curr->right;
            }
      }
        
      return candidate;
    }
};

/*
풀이해설 :
BST 구조를 다시보면 링크드리스트와 비슷한 부분이 있다.
현재 문제는 특정 조건의 값에 따라 노드를 반환하는 것이고
이 탐색의 기준은 링크드 리스트와 흡사하다.
*/