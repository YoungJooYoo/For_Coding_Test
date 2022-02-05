class Solution {
public:
    int dfs(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }
        
        int aaa[40000];
        int left_sum = max(dfs(root->left), 0);
        int right_sum = max(dfs(root->right), 0);
            
        int sum = root->val + left_sum + right_sum;
        max_sum = max(max_sum, sum);
        
        return root->val + max(left_sum, right_sum);
    }
    
    int maxPathSum(TreeNode* root) 
    {
        dfs(root);
        return max_sum;  
    }
    
private:
    int max_sum = INT_MIN;
};