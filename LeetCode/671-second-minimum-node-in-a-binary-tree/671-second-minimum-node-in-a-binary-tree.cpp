class Solution {
public:
	set<int> set;

	void dfs(TreeNode* root)
	{
		if (!root) {
			return;
		}

		set.insert(root->val);
		dfs(root->left);
		dfs(root->right);
	}

    int findSecondMinimumValue(TreeNode* root) 
	{
        dfs(root);

		if (set.size() > 1) {
			auto itr = set.begin();
			itr++;
			return *itr;
		}
		
		return -1;
    }
};