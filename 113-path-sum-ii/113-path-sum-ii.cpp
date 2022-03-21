class Solution {
public:
	void dfs(TreeNode* root, int targetSum, vector<int> path)
	{
		if (root == nullptr) {
			return;
		}

		/* Tree의 Leaf까지 도달했고 targerSum에 도달한 경우 */
		if (root->val == targetSum && root->left == nullptr && root->right == nullptr) {
			path.push_back(root->val);
			result.push_back(path);
		}

		path.push_back(root->val);
		dfs(root->left, targetSum - root->val, path);
		dfs(root->right, targetSum  - root->val, path);
	}

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
	{
          vector<int> path;
          dfs(root, targetSum, path);
          return result;
    }
private:
	vector<vector<int>> result;
};

/*
풀이법 :
dfs 함수의 매개변수 vector<int> temp를 참조를 하는 것이 아닌
매 함수 호출마다 path라는 배열이 새로 생긴다.
이를 통해 최적의 path만 저장한 배열 temp를 찾을 수 있다.

재귀를 호출할떄 
targetSum - root->val를 반복함으로 leaf노드에서 leadf node val == targetSum
이되는 순간이 문제에서 요구하는 path이다.
*/