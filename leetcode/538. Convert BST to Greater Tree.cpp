class Solution {
public:
    TreeNode* convertBST(TreeNode* root) 
    {
        convertBSTHelper(root);
        return root;
    }
    
private:
    void convertBSTHelper(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return;
        } 
        
        convertBSTHelper(root->right);  
        mSum += root->val; 
        root->val = mSum; 
        convertBSTHelper(root->left);
    }

    int mSum = 0;
};

// https://leetcode.com/problems/convert-bst-to-greater-tree/
