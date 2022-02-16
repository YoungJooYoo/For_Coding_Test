class Solution {
public:
bool countUnivalSubtreesRecursive(TreeNode* root, int& count)
    {
        if(root == NULL) {
            return true;
        }
            
        bool isLeftUnival = countUnivalSubtreesRecursive(root->left, count);
        bool isRightUnival = countUnivalSubtreesRecursive(root->right, count);
        
        // leaf까지와서 (좌 우 null), 체크하거나 혹은 노드의 좌우가 값이 노드의 값이랑 일치하는지 판단
        if (isLeftUnival && isRightUnival && ((root->left == NULL) || root->left->val == root->val) && ((root->right == NULL) || root->right->val == root->val)) {
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