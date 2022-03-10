class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (root == nullptr) {
            return nullptr;
        }
        if (root == p || root == q) { // 시작점이 p이거나 혹은 q라면 당연히 root가 답
            return root;
        }
        
        TreeNode* left_node = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_node = lowestCommonAncestor(root->right, p, q);
        
        if (left_node != nullptr && right_node != nullptr) {
            return root;
        }
        else if (left_node == nullptr && right_node == nullptr) {
            return nullptr;
        }
        else if (left_node != nullptr) {
            return left_node;
        }
        else if(right_node != nullptr) {
            return right_node;
        }
        
        return nullptr;
    }
};