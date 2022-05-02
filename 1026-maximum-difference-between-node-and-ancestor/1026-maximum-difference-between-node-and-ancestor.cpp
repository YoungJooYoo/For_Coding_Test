class Solution {
public:
    int maxAncestorDiff(TreeNode* root, int min_val = 100000, int max_val = 0) 
    {
        if (root == nullptr) {
            return max_val - min_val;
        }
        
        max_val = max(max_val, root->val);
        min_val = min(min_val, root->val);
        
        return max(maxAncestorDiff(root->left, min_val, max_val), maxAncestorDiff(root->right, min_val, max_val));
    }
};