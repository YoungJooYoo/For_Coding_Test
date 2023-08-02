class Solution {
public:
    void dfs(TreeNode* root, int level, int x, int y, int temp)
    {
        if (root == nullptr) {
            return;
		}

		/*레벨과 유니크한 부모 노드의 값을 기록한다. */
        if (root->val == x) {
            parent_x = temp;
            level_x = level;
        }
        if (root->val == y) {
            parent_y = temp;
            level_y = level;
        }
        
        dfs(root->left, level + 1, x, y, root->val);
        dfs(root->right, level + 1, x, y, root->val);

        return;
    }

    bool isCousins(TreeNode* root, int x, int y) 
	{
        dfs(root, 0, x, y, 0);

		/* 문제조건 노드의 깊이가 같고, 부모 모드가 다른 경우 true */
        if (level_x == level_y && parent_x != parent_y) {
            return true;
		}

        return false;
    }

private:
    int parent_x;
	int parent_y;
    int level_x;
	int level_y;
};