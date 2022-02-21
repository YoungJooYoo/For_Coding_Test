class Solution {
public:
  int solve(TreeNode* root)
  {
        if (root == nullptr) {
			return 0;
		}

        int left = solve(root->left); // root로 시작해 왼쪽 최대 깊이
        int right = solve(root->right); // root로 시작해 오른쪽 최대 깊이
        ans = max(ans, left + right); // 좌우좌우 구하면서 가장 최대를 찾는다.

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root)
	{
        solve(root);
        return ans;
    }

private:
	int ans = 0;
};

/*
 풀이법 :
 root로 부터 left 깊이 righr 깊이를 구해 두 깊이를 더하면 된다.
 left, right의 각각 깊이를 구한다.
*/