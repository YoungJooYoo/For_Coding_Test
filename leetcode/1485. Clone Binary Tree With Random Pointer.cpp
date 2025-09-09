class Solution
{
public:
    NodeCopy* copyRandomBinaryTree(Node* const root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        NodeCopy* const cloned = cloneRecursive(root);
        assert(MIN_NODES <= mTotalNodeCount && mTotalNodeCount <= MAX_NODES);

        return cloned;
    }

private:
    NodeCopy* cloneRecursive(Node* const node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        else if (mVisited.find(node) != mVisited.end())  // 이미 복제된 노드라면 재사용
        {
            return mVisited[node];
        }
        assert(MIN_VAL <= node->val && node->val <= MAX_VAL);

        ++mTotalNodeCount;
        auto& currentNode = mVisited[node];
        currentNode = new NodeCopy(node->val);
        currentNode->left   = cloneRecursive(node->left);
        currentNode->right  = cloneRecursive(node->right);
        currentNode->random = cloneRecursive(node->random);

        return currentNode;
    }

private:
    unordered_map<Node*, NodeCopy*> mVisited;
    int mTotalNodeCount = 0;

    enum
    {
        MIN_NODES = 0,
        MAX_NODES = 1000,
        MIN_VAL   = 1,
        MAX_VAL   = 1000000
    };
};

// https://leetcode.com/problems/clone-binary-tree-with-random-pointer/description/
