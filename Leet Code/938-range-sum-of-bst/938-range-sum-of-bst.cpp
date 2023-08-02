class Solution {
public:
    void dfs(TreeNode* root)
    {
        if (root == nullptr) {
            return;
        }
        if (low_range <= root->val && root ->val <= high_range) {
            sum = sum + root->val;
        }
        
        dfs(root->left);
        dfs(root->right);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        low_range = low;
        high_range = high;
        
        dfs(root);      
        return sum;
    }

private:
    int sum = 0;
    int low_range;
    int high_range;
};