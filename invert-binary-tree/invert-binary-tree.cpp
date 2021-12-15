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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* node = root;
        TreeNode* temp;
        
        if (node == NULL) {
            return node;
        }
        // 노드 위치 변경
        temp = node->left;
        node->left = node->right;
        node->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        
        return node;
    }
};