/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = root;
        
        // 값이 정렬된 이진트리 이므로
        while (node != NULL && node->val != val) {
            if(node->val > val) {  // val이 크면 왼쪽 탐색
                node = node->left;
            }
	        else { // val이 크면 오른쪽 탐색
                node = node->right;
            }
        }
        
        return node;
    }
};