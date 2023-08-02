class Solution {
public:
    void dfs(TreeNode* root) 
    {
        if (root == nullptr) {
            return;
        }
            
        if (root->left && root->right == nullptr) {
            lonely_node.push_back(root->left->val);
        }
        else if (root->left == nullptr && root->right) {
            lonely_node.push_back(root->right->val);
        }

        dfs(root->left);
        dfs(root->right);
    }

    vector<int> getLonelyNodes(TreeNode* root) 
    {
        dfs(root);
        return lonely_node;
    }

private:
    vector<int> lonely_node;
};

// https://leetcode.com/problems/find-all-the-lonely-nodes/description/
