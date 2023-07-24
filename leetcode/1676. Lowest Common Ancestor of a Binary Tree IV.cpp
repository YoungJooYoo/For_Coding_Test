class Solution {
private:
    unordered_set<TreeNode *> nodeSet;
    TreeNode *res = NULL;
    
    bool dfs(TreeNode *curr) 
    {
        if (curr == NULL) return false;

        bool lRes = dfs(curr->left);
        bool rRes = dfs(curr->right);
        bool currRes = nodeSet.count(curr) != 0; // root노드가 set에 들어 있는지 확인

        if (currRes || (lRes && rRes)) res = curr; // 좌우 노드에도 존재하고, 루트도 존재한다면, res = curr

        return currRes || lRes || rRes;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) 
    {
        for (TreeNode* node : nodes) {
            nodeSet.insert(node);
        }
        dfs(root);

        return res;
    }
};

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/description/
