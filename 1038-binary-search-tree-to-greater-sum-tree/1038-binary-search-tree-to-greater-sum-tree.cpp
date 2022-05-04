class Solution {
public:
    void dfs(TreeNode* root) 
    { 
        if (root == nullptr) {
            return;
        }
        dfs(root->right);
        sum = sum + root->val;
        root->val = sum;
        dfs(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) 
    {
        dfs(root);
        return root;
    }
    
private:
    int sum = 0;
};