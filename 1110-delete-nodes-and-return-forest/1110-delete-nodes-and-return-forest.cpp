class Solution {
public:
    void dfs(TreeNode* &root, vector<int>& to_delete) 
    {
        if (root == nullptr) {
            return;
        } 
        
        dfs(root->left, to_delete);
        dfs(root->right, to_delete);
        
        // to_delete 배열에 root->val 값이 있는지 확인한다. 없다면 end를 반환
        if (find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()) {
            if (root->left) {
                result.push_back(root->left);
            }
            if (root->right) {
                result.push_back(root->right);
            }
            root = nullptr;
            delete root;
                
        }
        
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        dfs(root, to_delete);
        
        if (root) {
            result.push_back(root);
        }
        
        return result;
    }
    
private:
   vector<TreeNode*> result;
};