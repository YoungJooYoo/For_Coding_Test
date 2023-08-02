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
    
    dfs(node->left); // 먼저 left 방문
    dfs(node->right); // left 방문 후, right 방문
    result.push_back(node->val); // 마지막 루트 방문, value 벡터에 저장
} 
    
public:
    vector<int> postorderTraversal(TreeNode* root)  {
        TreeNode* node = root;
        
        if (node == NULL) {
            return result;
        }
        
        dfs(node); // 1번 노드 부터 순회
        
        return result;
    }
};
