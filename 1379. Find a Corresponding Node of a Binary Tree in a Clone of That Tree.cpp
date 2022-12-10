class Solution {
public:
    void recursive(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        else if (root->val == target_root->val)
        {
            result = root;
        }

        recursive(root->left);
        recursive(root->right);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        clnoed_root = cloned;
        target_root = target;

        recursive(cloned);

        return result;
    }

private:
    TreeNode* clnoed_root;
    TreeNode* target_root;
    TreeNode* result;
};
