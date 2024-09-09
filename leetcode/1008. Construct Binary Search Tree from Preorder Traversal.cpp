class Solution 
{
public:
    TreeNode* bstFromPreorder(const vector<int>& preorder) 
    {
        assert(preorder.size() != 0);
        TreeNode* root = nullptr;

        for (const auto elem : preorder)
        {
            root = bstFromPreorderHelper(root, elem);
        }

        return root;
    }
private:
    TreeNode* bstFromPreorderHelper(TreeNode* root, const int value)
    {
        if (root == nullptr)
        {
            root = new TreeNode(value);
        }
        else if (root->val < value)
        {
            root->right = bstFromPreorderHelper(root->right, value);
        }
        else if (root->val > value)
        {
            root->left = bstFromPreorderHelper(root->left, value);
        }

        return root;
    }
};

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

/*

배열 탐색
8이 나외
// 값을 넣어
// 그리고 bst 탐색 후, 넣ㅎ기 null인 곳에

*/
