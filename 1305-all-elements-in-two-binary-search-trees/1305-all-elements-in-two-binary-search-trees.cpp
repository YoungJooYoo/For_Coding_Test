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
public:
    void dfs(TreeNode* root, vector<int>& result)
    {
        if (root == nullptr) {
            return;
        }
        
        result.push_back(root->val);
        dfs(root->left, result);
        dfs(root->right, result);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> result;
        
        dfs(root1, result);
        dfs(root2, result);
        sort(begin(result), end(result));
        
        return result;
    }
};