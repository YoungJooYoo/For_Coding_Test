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

int cnt_left = 0;
int cnt_right = 0;

class Solution {
int DFS(TreeNode* Node, int tree_level)
{
    TreeNode* node = Node;
    
    // 입력부 예외처리
    if (node == NULL) {
        return tree_level - 1;
    }
    if (node->left == NULL && node->right == NULL) {
        return tree_level;
    }
    
    return max(DFS(node->left, tree_level + 1), DFS(node->right, tree_level + 1));
}
    
public:
    int maxDepth(TreeNode* root) {
        TreeNode* node = root;
        
        int tree_level = 2; 
        
        // 입력부 예외처리
        if (node == NULL) {
            return 0;
        }
        if (node->left == NULL && node->right == NULL) {
            return 1;
        }
        
        return max(DFS(node->left, tree_level), DFS(node->right, tree_level));
    }
};