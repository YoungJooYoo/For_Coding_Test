class Solution {
public:
    bool isLeaf(TreeNode* root){
        return root->left == nullptr && root->right == nullptr;
    }
    TreeNode* dfs(TreeNode* root, vector<int> &v, vector<vector<int>>& ans){
        if(root == nullptr)
            return root;
        if(isLeaf(root)){
            v.push_back(root->val);
            return nullptr;
        }
        root->left = dfs(root->left,v,ans);
        root->right = dfs(root->right,v,ans);
        return root;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int> > ans;
        while(root){
            vector<int> v;
            root = dfs(root,v,ans);
            ans.push_back(v);
        }
        return ans;
    }
};