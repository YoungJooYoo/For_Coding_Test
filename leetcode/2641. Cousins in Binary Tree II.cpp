class Solution 
{
public:
    TreeNode* replaceValueInTree(TreeNode* const root)
    {
        assert(root != nullptr);

        computeDepthSumRecursive(root, 0);
        updateValuesRecursive(root, 0);
        
        return root;
    }

private:
    void computeDepthSumRecursive(TreeNode* const node, const size_t depth)
    {
        if (node == nullptr)
        {
            return;
        }
        else if (depth < 2)
        {
            node->val = 0;
        }

        if (mDepthSum.find(depth) == mDepthSum.end())
        {
            mDepthSum[depth] = node->val;
        }
        else
        {
            mDepthSum[depth] += node->val;
        }
        
        computeDepthSumRecursive(node->left, depth + 1);
        computeDepthSumRecursive(node->right, depth + 1);
    }

    void updateValuesRecursive(TreeNode* const node, const size_t depth)
    {
        if (node == nullptr)
        {
            return;
        }
        else if (depth < 1)
        {
            node->val = 0;
        }
        else
        {
            if (node->left != nullptr && node->right != nullptr)
            {
                const int val = node->left->val + node->right->val;
                node->left->val = mDepthSum[depth + 1] - val;
                node->right->val = mDepthSum[depth + 1] - val;
            }
            else if (node->left != nullptr && node->right == nullptr)
            {
                node->left->val = mDepthSum[depth + 1] - node->left->val;
            }
            else if (node->left == nullptr && node->right != nullptr)
            {
                node->right->val = mDepthSum[depth + 1] - node->right->val;
            }
        }

        updateValuesRecursive(node->left, depth + 1);
        updateValuesRecursive(node->right, depth + 1);
    }

    unordered_map<int, int> mDepthSum;
};

// https://leetcode.com/problems/cousins-in-binary-tree-ii/description/
