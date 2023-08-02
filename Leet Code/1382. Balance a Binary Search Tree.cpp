class Solution {
public:
    void dfs(TreeNode* root) // in-order
    {
        if (root == nullptr) {
            return;
        }

        dfs(root->left);
        nodes.push_back(root);
        dfs(root->right);
    }

    TreeNode* helper(const int low, const int high)
    {
        if (low > high) {
            return nullptr;
        }

        const int mid = (low + high) / 2;
        nodes[mid]->left = helper(low, mid - 1);
        nodes[mid]->right = helper(mid + 1, high);

        return nodes[mid];
    }

    TreeNode* balanceBST(TreeNode* root)
    {
        dfs(root);
        return helper(0, nodes.size() - 1);
    }

private:
    vector<TreeNode*> nodes;
};

// https://leetcode.com/problems/balance-a-binary-search-tree/description/
