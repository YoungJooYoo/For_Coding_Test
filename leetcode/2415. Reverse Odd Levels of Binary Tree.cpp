class Solution {
public:
    void dfs(TreeNode* left, TreeNode* right, int level)
    {
        if (left == nullptr && right == nullptr) {
            return;
        }
        else if (level % 2 == 0 && left != nullptr && right != nullptr) {
            swap(left->val, right->val);
        }
        dfs(left->right, right->left, level + 1);
        dfs(left->left, right->right, level + 1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        if (root->left != nullptr && root->right != nullptr) {
            dfs(root->left, root->right, 0);
        }

        return root;
    }
};

// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/
