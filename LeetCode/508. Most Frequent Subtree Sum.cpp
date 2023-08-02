class Solution {
public:
    int dfs_recursive(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        int sum = root->val;
        sum += dfs_recursive(root->left);
        sum += dfs_recursive(root->right);
        freq[sum]++;
        max_freq_count = max(max_freq_count, freq[sum]);

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        dfs_recursive(root);

        for (const auto& elem : freq) {
            if (elem.second == max_freq_count) { // 최대 빈도수 원소만 result에 넣는다.
                result.push_back(elem.first);
            }
        }

        return result;
    }

private:
    vector<int> result;
    unordered_map<int, int> freq;
    int max_freq_count = 0; // 최대 빈도수
};

// https://leetcode.com/problems/most-frequent-subtree-sum/description/
