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
    vector<int> output;
    void inorder(TreeNode* ptree_node)
    {
        if (ptree_node == NULL) {
            return;
        }

        inorder(ptree_node->left);
        output.push_back(ptree_node->val);
        inorder(ptree_node->right);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* ptree_node = root;

        // inorder -> 중위순회
        // 재귀로 탐색 구현
        inorder(ptree_node);

        return output;
    }
};