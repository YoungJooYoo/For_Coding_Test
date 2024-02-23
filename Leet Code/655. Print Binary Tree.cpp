class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) 
    {
        const size_t depth = get_depth(root, 0); // 깊이가 행,
        const size_t length = pow(2, depth) - 1;
        vector<vector<string>> result(depth, vector<string>(length)); // 2^n -1 -> 열의길이

        print_tree(root, 0, 0, length - 1, result);

        return result;
    }

private:
    size_t get_depth(TreeNode* root, const size_t depth)
    {
        if (root == nullptr) {
            return depth;
        }

        const size_t depth_1 = get_depth(root->left, depth + 1);
        const size_t depth_2 = get_depth(root->right, depth + 1);

        return max(depth_1, depth_2);
    }

    void print_tree(TreeNode* root, const size_t depth, const size_t left, const size_t right, vector<vector<string>>& result)
    {
        if (root == nullptr) {
            return;
        }

        const size_t mid = left + (right - left) / 2;
        result[depth][mid] += to_string(root->val);
        print_tree(root->left, depth + 1, left, mid - 1, result);
        print_tree(root->right, depth + 1, mid + 1, right, result);
    }
};

// https://leetcode.com/problems/print-binary-tree/description/
