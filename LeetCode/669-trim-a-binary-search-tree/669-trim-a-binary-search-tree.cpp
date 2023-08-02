class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        if (root == nullptr) { // 재귀 종료조건
            return nullptr;
        }
        if (root->val < low) { // BST이므로, 정렬이 된 값, low보다 작다면 low보다 큰 right 선택
            return trimBST(root->right, low, high);
        }
        if (high < root->val) { // BST이므로, 정렬이 된 값, high보다 크다면 high보다 작은 left 선택
            return trimBST(root->left, low, high);
        }
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        return root;
    }
};