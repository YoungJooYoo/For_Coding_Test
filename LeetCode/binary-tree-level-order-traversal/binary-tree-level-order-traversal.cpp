class Solution {
void bfs(TreeNode* root, size_t level, vector<vector<int>>& result)
{
    TreeNode* node = root;
        
        if (node == NULL) {
            return;
        }
        if (result.size() == level) {
            result.push_back({});
        }
    
        result[level].push_back(node->val);
    
        if (node->left) {
            bfs(node->left, level + 1, result);
        } 
    
        if (node->right) {
             bfs(node->right, level + 1, result);
        }
}
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        TreeNode* node = root;
        vector<vector<int>> result;
        bfs(node, 0, result);
        
        return result;
    }
};
