class Solution {
public:
    void recursive(TreeNode* root)
    {
        if (root == nullptr) {
            return;   
        }
        
        elements.push_back(root->val);

        recursive(root->left);
        recursive(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) 
    {
        recursive(root);
        
        for (size_t i = 0; i < elements.size() - 1; i++) {
            for (size_t j = i + 1; j < elements.size(); j++) {
                if (elements[i] + elements[j] == k) {
                    return true;
                }
            }
        }
        
        return false;
    }

private:
    vector<int> elements;
};