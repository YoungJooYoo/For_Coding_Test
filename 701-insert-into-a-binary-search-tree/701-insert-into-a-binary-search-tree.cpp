class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        TreeNode* curr = root;
        TreeNode* prev;
        
        if (root == nullptr) {
            root = new TreeNode;
            root->val = val;
            return root;
        }
        
        while (curr != nullptr) {
            prev = curr;
            if (val < curr->val) { // 왼쪽탐색
                curr = curr->left;
            }
            else { // val > curr->val 오른쪽탐색
                curr = curr->right;
            }
        }
        
        // null이 오기전에 트리를 추가하기
        if (val < prev->val) {
            prev->left = new TreeNode;
            prev->left->val = val;
        }
        else {
            prev->right = new TreeNode;
            prev->right->val = val;
        }
        
        return root;
    }
};