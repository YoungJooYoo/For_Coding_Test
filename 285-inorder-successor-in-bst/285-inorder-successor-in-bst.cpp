/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        TreeNode* candidate = nullptr;
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            if (p->val < curr->val) {
              candidate = curr;
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