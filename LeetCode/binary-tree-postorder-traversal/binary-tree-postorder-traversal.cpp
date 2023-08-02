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
    vector<int> result;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* ptree_node = root;
        postorder(ptree_node, result);

        return result;
    }

    void postorder(TreeNode* ptree_node, vector<int>& result) {
        
        if (ptree_node == NULL) {
            return;
        }
        
        postorder(ptree_node->left, result);
        postorder(ptree_node->right, result);
        result.push_back(ptree_node->val);
    }
};

