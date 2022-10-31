class Solution {
public:
    bool evaluateTree(TreeNode* root) 
    {
        switch (root->val)
        {
            case FALSE:
            case TRUE:
                return root->val; // return true or false
            case OR:
                return evaluateTree(root->left) || evaluateTree(root->right);
            case AND:
                return evaluateTree(root->left) && evaluateTree(root->right);
        }
        
        return false;
    }
    
private: 
    enum 
    {
        FALSE = 0,
        TRUE = 1,
        OR = 2,
        AND = 3
    };
};