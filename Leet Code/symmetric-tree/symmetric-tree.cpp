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
    
bool solve(TreeNode* left_node, TreeNode* right_node) {
	    TreeNode* left = left_node;
        TreeNode* right = right_node;
    
        // 좌우 트리가 대칭이면 true
        if (left == NULL && right == NULL) {
            return true;
        }
        
        // 대칭이 아니므로 false
	    if ((left == NULL && right != NULL) || (left != NULL && right == NULL)) {
            return false;
        }
        
        // 값이 달라서 false
	    if (left->val != right->val) {
            return false;
        }
        
        // 좌우 대칭 비교 둘다 같으면 true를 반환, 두 solve return이 true일때만 true를 최종적으로 반환
	    return solve(left->left, right->right) && solve(left->right, right->left);
}
    
public:
	bool isSymmetric(TreeNode* root) {
		TreeNode* node = root;
        
        // 입력값 예외처리 
        if (node == NULL) {
            return true;
        }
        
		return solve(root->left, root->right);
	}
};