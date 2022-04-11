class Solution {
public:
void dfs(TreeNode* root)
	{
		if (root == nullptr) {
			return;
		}
		nums.push_back(root->val);
		dfs(root->left);
		dfs(root->right);
	}

int getMinimumDifference(TreeNode* root) 
	{
		dfs(root);
		//sort(result.begin(), result.end()); 이유는 모르겠으나 정렬 작동안함
		sort(nums.begin(), nums.end(), greater<int>());

		for (size_t i = 0; i < nums.size() - 1; i++) {
			result.push_back(abs(nums[i] - nums[i + 1]));
		}
		
		return *min_element(result.begin(), result.end());
    }

private:
	vector<int> nums;
	vector<int> result;
};