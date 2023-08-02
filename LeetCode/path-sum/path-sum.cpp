/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    bool result = false;
    
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        TreeNode* node = root;
        int sum = 0;
        
        dfs(node, targetSum, sum);

        return result;
    }
    
    void dfs(TreeNode* root, int targetSum, int sum)
    {
        TreeNode* node = root;
        
        if (node == NULL) {
            return; 
        }
        
        sum = sum + node->val;
        
        if (node->left == NULL && node->right == NULL) { // 좌우가 NULL이면 leaf도착 
            if (sum == targetSum) { // leaf까지 내려온 sum이 targetSum이랑 비교
                result = true;
                return;
             } 
        }
        
        dfs(node->left, targetSum, sum);
        dfs(node->right, targetSum, sum);
    }
};