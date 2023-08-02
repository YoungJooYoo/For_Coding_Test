class Solution {
public:
bool isEqual(TreeNode* root,TreeNode* subRoot) 
	{
        if (root == NULL || subRoot == NULL) {
            return (root == subRoot) ? true : false;
        }
        if (root->val != subRoot->val) {
            return false;
        }

        return isEqual(root->left, subRoot->left) && isEqual(root->right, subRoot->right);
    }
	
  	bool isSubtree(TreeNode* root, TreeNode* subRoot) 
	{
        if (root == NULL) {
            return false;
        }
        if (isEqual(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};