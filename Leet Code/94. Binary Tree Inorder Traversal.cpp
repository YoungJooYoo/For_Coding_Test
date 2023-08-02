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
class Solution  {
vector<int> result;

void dfs(TreeNode* root) {
    TreeNode* node = root;
    
    if (node == NULL) {
        return;
    }
    
    dfs(node->left); // left 방문
    result.push_back(node->val); // root 방문하고, 방문한 value 벡터에 저장
    dfs(node->right); // root 방문 후, right 방문
} 
    
public:
    vector<int> inorderTraversal(TreeNode* root)  {
        TreeNode* node = root;
        
        if (node == NULL) {
            return result;
        }
        
        dfs(node); // 1번 노드 부터 순회
        
        return result;
    }
};
