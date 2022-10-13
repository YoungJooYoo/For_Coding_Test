class Solution {
public:
    void recursive_helper(TreeNode* root)
    {
        if (root == nullptr) {
            return;
        }
        
        result += to_string(root->val);
        
        if (root->left != nullptr) {
            result += "(";
            recursive_helper(root->left);
            result += ")";
        } 
        
        if (root->right != nullptr) {
            if (root->left == nullptr) {
                result += "()";
            }
            
            result += "(";
            recursive_helper(root->right);
            result += ")";
        }       
    }
    
    string tree2str(TreeNode* root) 
    {
        recursive_helper(root);
        
        return result;
    }
    
private:
    string result = "";
};