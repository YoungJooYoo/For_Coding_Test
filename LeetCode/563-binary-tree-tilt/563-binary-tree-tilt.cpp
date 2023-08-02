class Solution {
public:
    int dfs(TreeNode* root) 
	{
        if (root == nullptr) {
			return 0;
		}

        int left = dfs(root->left);
        int right = dfs(root->right);
        int tilt = abs(left - right);
        result = result + tilt;

        return left + right + root->val;
    }
    
    int findTilt(TreeNode* root) 
	{
        dfs(root);
        return result;
    }
    
private:
    int result = 0;
};