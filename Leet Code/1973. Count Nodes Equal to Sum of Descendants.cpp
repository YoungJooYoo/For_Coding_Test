class Solution {
public:
    long long dfs(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        long long sum = dfs(root->left) + dfs(root->right);
    
        if (sum == root->val) ++count;

        return sum + root->val;
    }

    int equalToDescendants(TreeNode* root) 
    {
        dfs(root);

        return count;
    }

private:
    int count = 0;
};

// https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/description/
