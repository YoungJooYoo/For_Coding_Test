class Solution {
public:
bool countUnivalSubtreesRecursive(TreeNode* root, int& count)
    {
        if(root == NULL) {
            return true;
        }
            
        bool isLeftUnival = countUnivalSubtreesRecursive(root->left, count);
        bool isRightUnival = countUnivalSubtreesRecursive(root->right, count);
            
        if (isLeftUnival && isRightUnival
            && ((root->left == NULL) || root->left->val == root->val)
            && ((root->right == NULL) || root->right->val == root->val)
        ) {
            ++count;
            return true;
        }
    
        return false;
    }
    
    int countUnivalSubtrees(TreeNode* root) 
    {
        int count = 0;
        countUnivalSubtreesRecursive(root, count);
        return count;
    }
};