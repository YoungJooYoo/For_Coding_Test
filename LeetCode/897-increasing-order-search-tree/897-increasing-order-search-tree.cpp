class Solution {
public:
    void dfs(TreeNode* root) 
    {
        if (root == nullptr) {
            return;
        }
        
        nums.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) 
    {
        dfs(root);
        sort(nums.begin(), nums.end());
        
        TreeNode* head = new TreeNode;
        TreeNode* curr = head;
        
        for (size_t i = 0; i < nums.size(); i++) {
            curr->right = new TreeNode;
            curr = curr->right;
            curr->val = nums[i];
        }
        
        return head->right;
    }
    
private:
    vector<int> nums;
};