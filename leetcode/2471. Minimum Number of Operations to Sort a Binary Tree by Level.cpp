class Solution
{
public:
    int minimumOperations(const TreeNode* root)
    {
        assert(root != nullptr);
        collectByDepthRecursive(root, 0);

        int result = 0;
        
        for (int depth = 0; depth < mMaxDepth; ++depth)
        {
            result += bubblesortCount(depth);
        }

        assert(result >= 0);
        return result;
    }

private:
    void collectByDepthRecursive(const TreeNode* node, const int depth)
    {
        if (node == nullptr)
        {
            return;
        }
    assert(MIN_NODE_VAL <= node->val && node->val <= MAX_NODE_VAL);
        if (static_cast<int>(mLevelValues.size()) == depth)
        {
            mLevelValues.push_back(vector<int>());
        }

        mLevelValues[depth].push_back(node->val);
        mMaxDepth = max(mMaxDepth, depth + 1);
        collectByDepthRecursive(node->left, depth + 1);
        collectByDepthRecursive(node->right, depth + 1);
        
    }

    int bubblesortCount(const int depth)
    {
        vector<int>& values = mLevelValues[depth];
        const int LENGTH = static_cast<int>(values.size());
        vector<pair<int, int>> valueIndexPairs;
        valueIndexPairs.reserve(LENGTH);

        for (int i = 0; i < LENGTH; ++i)
        {
            valueIndexPairs.emplace_back(values[i], i);
        }

        sort(valueIndexPairs.begin(), valueIndexPairs.end());
        vector<bool> isVisited(LENGTH, false);
        int swapCount = 0;

        for (int i = 0; i < LENGTH; ++i)
        {
            if (isVisited[i] || valueIndexPairs[i].second == i)
            {
                continue;
            }

            int cycleSize = 0;
            int currentIndex = i;

            while (!isVisited[currentIndex])
            {
                isVisited[currentIndex] = true;
                currentIndex = valueIndexPairs[currentIndex].second;
                ++cycleSize;
            }

            if (cycleSize > 1)
            {
                swapCount += cycleSize - 1;
            }
        }

        return swapCount;
    }

private:
    vector<vector<int>> mLevelValues; // index == depth, element == node values at that depth
    int mMaxDepth = 0;

    enum
    {
        UNUSED = 0,
        MIN_NODE_VAL = 1,
        MAX_NODE_VAL = 100000
    };
};
// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/
