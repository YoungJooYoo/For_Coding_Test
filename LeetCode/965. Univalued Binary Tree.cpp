class Solution {
public:
    void dfs(TreeNode* root)
    {
        if (root == nullptr) {
            return;
        }

        if (root->val != value) {
            flag = false;
        }

        dfs(root->left);
        dfs(root->right);
    }

    bool isUnivalTree(TreeNode* root) 
    {
        value = root->val;
        dfs(root);

        return flag;
    }

private:
    int value;
    bool flag = true;
};

// https://leetcode.com/problems/univalued-binary-tree/description/
