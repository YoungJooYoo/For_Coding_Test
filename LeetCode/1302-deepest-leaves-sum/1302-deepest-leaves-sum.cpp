class Solution 
{
public:
    void get_max_depth(TreeNode* root, int depth) 
    {
        if (root == nullptr) {
            return;
        }
        
        depth++;
        max_depth = max(max_depth, depth);
        get_max_depth(root->left, depth);
        get_max_depth(root->right, depth);
    }
    
    void get_deepest_sum(TreeNode* root, int depth)
    {
        if (root == nullptr) {
            return;
        }
        
        depth++;
        
        if (depth == max_depth) {
            sum += root->val;
        } 
        
        get_deepest_sum(root->left, depth);
        get_deepest_sum(root->right, depth);
    }
    
    int deepestLeavesSum(TreeNode* root) 
    {
        get_max_depth(root, 0);
        get_deepest_sum(root, 0);
        
        return sum;
    }

private:
    int max_depth = 0;
    int sum = 0;
};