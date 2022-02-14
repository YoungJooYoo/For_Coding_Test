class Solution {
public:
    bool isLeaf(TreeNode* root){
        return root->left == nullptr && root->right == nullptr ? true : false;
    }
    
    TreeNode* dfs(TreeNode* root, vector<int>& v, vector<vector<int>>& ans) 
    {
        if (root == nullptr) {
            return root;
        }
        
        if (isLeaf(root)) {
            v.push_back(root->val);
            return nullptr;
        }
        
        root->left = dfs(root->left,v,ans);
        root->right = dfs(root->right,v,ans);
        
        return root;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) 
    {
        vector<vector<int> > ans;
        vector<int> v;
        
        while (root != nullptr) {
            root = dfs(root, v, ans);
            ans.push_back(v);
            v.clear();
        }
        
        return ans;
    }
};