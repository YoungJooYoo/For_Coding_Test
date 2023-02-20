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

    int minDiffInBST(TreeNode* root) 
    {
        dfs(root);
        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size() - 1; ++i) {
            int temp = abs(nums[i] - nums[i + 1]);
            min_differnce = min(min_differnce, temp);
        }

        return min_differnce;
    }

private:
    vector<int> nums;
    int min_differnce = INT_MAX;
};

// https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
