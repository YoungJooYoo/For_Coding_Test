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
private:
    int ans = 0;
    
    void dfs(TreeNode* root)
    {
        if (root == nullptr) {
            return;
        }
        
        // 끝의 좌측 노드인지 확인, 자식 노드가 좌우로 없어야하며, null이 아닌 것
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
             ans = ans + root->left->val;
        }
        
        dfs(root->left);
        dfs(root->right);
        
        return;
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        dfs(root);
        
        return ans;
    }
};