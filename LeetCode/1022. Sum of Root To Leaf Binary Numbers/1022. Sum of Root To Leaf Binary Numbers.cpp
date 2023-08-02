class Solution {
public:
    void dfs(TreeNode* root, int value)
    {
        if (root == nullptr) {
            return;
        }
        
        value = value << 1 | root->val; // 비트연산 더하기

        if(root->left == nullptr && root->right == nullptr) {
            result += value;
        }

        dfs(root->left, value);
        dfs(root->right, value);
    }

    int sumRootToLeaf(TreeNode* root) 
    {
        dfs(root, 0);

        return result;
    }

private:
    int result = 0;
};

// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
