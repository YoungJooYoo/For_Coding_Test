class Solution {
public:
    int getDepth(TreeNode* root) {
        if (!root)
            return 0;
        return max(getDepth(root->right), getDepth(root->left)) + 1;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root)
            return NULL;
        
        int right_depth = getDepth(root->right);
        int left_depth = getDepth(root->left);
        
        if (right_depth == left_depth)
            return root;
        
        if (right_depth > left_depth) 
            return subtreeWithAllDeepest(root->right);
        
        else 
            return subtreeWithAllDeepest(root->left);
    }
};