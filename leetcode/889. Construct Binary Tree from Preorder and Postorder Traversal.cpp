class Solution 
{
public:
    TreeNode* constructFromPrePost(const vector<int>& preorder, const vector<int>& postorder) const
    {
        assert(preorder.size() >= MIN_N && preorder.size() <= MAX_N);
        assert(postorder.size() >= MIN_N && postorder.size() <= MAX_N);
        assert(preorder.size() == postorder.size());
        
        return constructRecursive(preorder, 0, static_cast<int>(preorder.size()) - 1, postorder, 0, static_cast<int>(postorder.size()) - 1);
    }

private:
    TreeNode* constructRecursive(const vector<int>& preorder, const int preStart, const int preEnd, const vector<int>& postorder, const int postStart, const int postEnd) const
    {
        if (preStart > preEnd)
        {
            return nullptr;
        }
        
        TreeNode* const root = new TreeNode(preorder[preStart]);
        
        if (preStart == preEnd)
        {
            return root;
        }
        
        const int leftSubtreeRootVal = preorder[preStart + 1];
        int leftSubtreeRootIndex = postStart;
        while (leftSubtreeRootIndex <= postEnd && postorder[leftSubtreeRootIndex] != leftSubtreeRootVal)
        {
            leftSubtreeRootIndex++;
        }
        
        const int leftSubtreeSize = leftSubtreeRootIndex - postStart + 1;
        root->left = constructRecursive(preorder, preStart + 1, preStart + leftSubtreeSize, postorder, postStart, leftSubtreeRootIndex);
        root->right = constructRecursive(preorder, preStart + leftSubtreeSize + 1, preEnd, postorder, leftSubtreeRootIndex + 1, postEnd - 1);
        
        return root;
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = 30
    };
};

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/?envType=daily-question&envId=2025-02-23
