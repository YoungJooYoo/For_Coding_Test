class Solution {
private:
    bool dfs(TreeNode* root, TreeNode* min, TreeNode* max) {
        TreeNode* node = root;
        
        if(node == NULL) {
            return true;
        }
        if((min != NULL && node->val <= min->val) || (max != NULL && node->val >= max->val)) {
            return false;
        }
            
        return dfs(node->left, min, node) && dfs(node->right, node, max);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* node = root;
        
        if(node == NULL) {
            return true;
        }
        
        return dfs(node->left, NULL, node) && dfs(node->right, node, NULL);
    }
};