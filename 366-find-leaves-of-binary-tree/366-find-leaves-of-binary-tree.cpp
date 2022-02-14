class Solution {
public:
    bool isLeaf(TreeNode* root){
        return (root->left == nullptr && root->right == nullptr) ? true : false;
    }
    
    TreeNode* dfs(TreeNode* root) 
    {
        if (root == nullptr) {
            return nullptr;
        }
        
        if (isLeaf(root)) {
            temp.push_back(root->val);
            return nullptr;
        }
        
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        
        return root;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) 
    {
        while (root != nullptr) {
            root = dfs(root);
            ans.push_back(temp);
            temp.clear();
        }
        
        return ans;
    }
    
private:
    vector<vector<int>> ans;
    vector<int> temp;
    
};