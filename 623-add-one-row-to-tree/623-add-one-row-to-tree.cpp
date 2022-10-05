class Solution {
public:
    void addOneRowHelperRecursive(TreeNode* root, int val, int depth, int currentDepth)
    {
        if (root == nullptr) {
            return;
        }
        else if (currentDepth + 1 == depth) {
            TreeNode* tempLeft = root->left;
            TreeNode* tempRight = root->right;
            
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            
            TreeNode* currLeft = root->left;
            TreeNode* currRight = root->right;
            
            currLeft->left = tempLeft;
            currRight->right = tempRight;
        }
        
        addOneRowHelperRecursive(root->left, val, depth, currentDepth + 1);
        addOneRowHelperRecursive(root->right, val, depth, currentDepth + 1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if (depth == 1) {
            TreeNode* tempRoot = root;
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = tempRoot;
            newRoot->right = nullptr;
            root = newRoot;
            cout << "endl" << endl;
            
            return root;
        }
        
        addOneRowHelperRecursive(root, val, depth, 1);
        
        return root;
    }
};