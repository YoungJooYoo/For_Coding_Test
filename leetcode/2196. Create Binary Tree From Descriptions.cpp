class Solution 
{
public:
    TreeNode* createBinaryTree(const vector<vector<int>>& descriptions) 
    {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children; // mark childNode

        for (const auto& description : descriptions) 
        {
            const int parentVal = description[0];
            const int childVal = description[1];
            const int direction = description[2];

            // parent
            if (nodes.find(parentVal) == nodes.end())
            {
                nodes[parentVal] = new TreeNode(parentVal);
            }
            TreeNode* const parentNodde = nodes[parentVal];

            // child
            if (nodes.find(childVal) == nodes.end()) 
            {
                nodes[childVal] = new TreeNode(childVal);
            }
            TreeNode* const childNode = nodes[childVal];

            // link child to parent
            if (direction == LEFT)
            {
                parentNodde->left = childNode;
            }
            else if (direction == RIGHT)
            {
                parentNodde->right = childNode;
            }
            else
            {
                assert(false);
            }

            // mark child
            children.insert(childVal);
        }

        for (const auto& [val, node] : nodes)
        {
            if  (children.find(val) == children.end())
            {
                return nodes[val];
            }
        }

        return nullptr;
    }

private:
    enum 
    { 
        LEFT = 1, 
        RIGHT = 0
    };
};

// https://leetcode.com/problems/create-binary-tree-from-descriptions/description/
