class Solution {
public:
    void dfs (const TreeNode* const root)
    {
        if (root == nullptr) {
            return;
        }

        ++count;
        dfs(root->left);
        dfs(root->right);
    }

    int countNodes(const TreeNode* const const root) 
    {
        dfs(root);
        return count;
    }

private: 
    int count = 0;
};
