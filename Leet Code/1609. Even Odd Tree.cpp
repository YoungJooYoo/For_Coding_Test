class Solution {
public:
    bool isEvenOddTree(TreeNode* root) 
    {
        if (root == nullptr) {
            return false;
        }

        queue<TreeNode*> q;
        size_t level = 0;

        q.push(root);
        while (!q.empty()) {
            const size_t queueLength = q.size();
            vector<int> currentLevelValues;

            for (size_t i = 0; i < queueLength; ++i) {
                const TreeNode* currentNode = q.front(); 
                q.pop();
                currentLevelValues.push_back(currentNode->val);
                if (currentNode->left != nullptr) q.push(currentNode->left);
                if (currentNode->right != nullptr) q.push(currentNode->right);
            }

            if (level % 2 == 0) {
                for (const int val : currentLevelValues) {
                    if (val % 2 == 0) return false;
                }
                if (!isStrictlyIncreasing(currentLevelValues)) return false;
            } else {
                for (const int val : currentLevelValues) {
                    if (val % 2 != 0) return false;
                }
                if (!isStrictlyDecreasing(currentLevelValues)) return false;
            }
            ++level;
        }

        return true;
    }

private:
    bool isStrictlyIncreasing(const vector<int>& values) const {
        for (size_t i = 0; i < values.size() - 1; ++i) {
            if (values[i] >= values[i + 1]) return false;
        }
        return true;
    }

    bool isStrictlyDecreasing(const vector<int>& values) const {
        for (size_t i = 0; i < values.size() - 1; ++i) {
            if (values[i] <= values[i + 1]) return false;
        }
        return true;
    }
};

// https://leetcode.com/problems/even-odd-tree/description/?envType=daily-question&envId=2024-02-29
