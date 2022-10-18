class Solution {
public:
    void helper_recursive(TreeNode* root) 
    {
        if (root == nullptr) {
            return;
        }
        
        map[root->val]++;
        max_freq_value = max(max_freq_value, map[root->val]);
        
        helper_recursive(root->left);
        helper_recursive(root->right);
        
        return;
    }
    
    vector<int> findMode(TreeNode* root) 
    {
        vector<int> result;
        
        helper_recursive(root);
        
        for (const auto& elem : map){
            if (elem.second == max_freq_value) result.push_back(elem.first);
        }
        
        return result;
    }
    
private:
    unordered_map<int, int> map;
    int max_freq_value = 0;
};