class Solution 
{
public:
    const vector<int> largestValues(const TreeNode* const root)
    {
        traverseTreeRecursive(root, 0);
        extractMaxValuesPerDepth();

        return mResult;
    }

private:
    void traverseTreeRecursive(const TreeNode* const root, const int depth)
    {
        if (root == nullptr)
        {
            return;
        }

        mDepthToValues.insert({depth, root->val});
        traverseTreeRecursive(root->left, depth + 1);
        traverseTreeRecursive(root->right, depth + 1);
    }

    void extractMaxValuesPerDepth()
    {
        if (mDepthToValues.empty() == true)
        {
            return;
        }
        
        int currentMax = mDepthToValues.begin()->second; 
        int currentDepth = mDepthToValues.begin()->first;

        for (const auto& [depth, value] : mDepthToValues)
        {
            if (depth == currentDepth) 
            {
                if (value > currentMax) 
                {
                    currentMax = value;
                }
            }
            else 
            {
                mResult.push_back(currentMax);
                currentMax = value;
                currentDepth = depth;
            }
        }

        mResult.push_back(currentMax);
    }

    multimap<int, int> mDepthToValues; // depth - values mapping
    vector<int> mResult;
};

// solution 2

class Solution 
{
public:
    vector<int> largestValues(const TreeNode* const root)
    {
        if (root == nullptr) 
        {
            return mResult;
        }

        traverseTree(root, 0);
        extractMaxValuesPerDepth();

        return mResult;
    }

private:
    void traverseTree(const TreeNode* const node, const int depth)
    {
        if (node == nullptr) 
        {
            return;
        }

        mDepthToMaxHeap[depth].push(node->val);
        traverseTree(node->left, depth + 1);
        traverseTree(node->right, depth + 1);
    }

    void extractMaxValuesPerDepth()
    {
        int depth = 0;
        while (mDepthToMaxHeap.count(depth))
        {
            mResult.push_back(mDepthToMaxHeap[depth].top());
            ++depth;
        }
    }

    unordered_map<int, priority_queue<int>> mDepthToMaxHeap; // 각 깊이에 대한 최대 힙
    vector<int> mResult;
};


// https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/?envType=daily-question&envId=2024-12-25
