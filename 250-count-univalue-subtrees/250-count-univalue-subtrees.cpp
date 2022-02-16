class Solution {
public:
bool count_unival_subtrees_recursive(TreeNode* root, int& count)
    {
        if(root == NULL) {
            return true;
        }
            
        bool is_left_unival = count_unival_subtrees_recursive(root->left, count);
        bool is_right_unival = count_unival_subtrees_recursive(root->right, count);
        
        // leaf까지와서 (좌 우 null), 체크하거나 혹은 노드의 좌우가 값이 노드의 값이랑 일치하는지 판단
        if (is_left_unival && is_right_unival && ((root->left == NULL) || root->left->val == root->val) && ((root->right == NULL) || root->right->val == root->val)) {
            ++count;
            return true;
        }
    
        return false;
    }
    
    int countUnivalSubtrees(TreeNode* root) 
    {
        int count = 0;
        count_unival_subtrees_recursive(root, count);
        return count;
    }
};