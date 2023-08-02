class Solution {
public:
    int minDepth(TreeNode* root) {
        TreeNode* node = root;
        
        if (node == NULL) {
            return 0;
        }
        if (node->left == NULL) {
            return 1 + minDepth(node->right);
        }
        if (node->right == NULL) {
            return 1 + minDepth(node->left);
        }
        
        return 1 + min(minDepth(node->left), minDepth(node->right));
    }
};