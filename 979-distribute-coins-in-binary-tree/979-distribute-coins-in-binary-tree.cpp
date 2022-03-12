class Solution {
public:
    int distributeCoins(TreeNode* root) 
    {   
        dfs(root);
        
        return ans;
    }
    
private:
    int dfs(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        ans = ans + abs(left) + abs(right);
        
        return root->val + left + right - 1;
    }
    
    int ans = 0;
};