class Solution {
public:
    void helper_recursive(TreeNode* root) 
    {
        if (root == nullptr) {
            return;
        }
        
        map[root->val]++;
        fre = max(fre, map[root->val]);
        
        helper_recursive(root->left);
        helper_recursive(root->right);
        
        return;
    }
    
    vector<int> findMode(TreeNode* root) 
    {
        vector<int> res;
        
        fre = 0;
        helper_recursive(root);
        
        for (const auto& elem : map){
            if (elem.second == fre) res.push_back(elem.first);
        }
        
        return res;
    }
    
private:
    unordered_map<int, int> map;
    int fre;
};