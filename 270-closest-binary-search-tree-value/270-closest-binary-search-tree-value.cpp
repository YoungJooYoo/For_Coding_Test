class Solution {
public:
    int closestValue(TreeNode* root, double target) 
    {
        vector<int> nums;
        vector<int> values;
        int int_target = target + 0.5;
        
        dfs(root, nums);
        sort(nums.begin(), nums.end());
        
        for (const auto& num : nums) cout << num << ", ";
        cout << endl;
        
        for (size_t i = 0; i < nums.size(); i++) {
            values.push_back(abs(nums[i] - int_target));
        }
        
        int min_index = min_element(values.begin(), values.end()) - values.begin();
        
        for (const auto& num : values) cout << num << ", ";
        cout << endl;
        
        int min = *min_element(nums.begin(), nums.end());
        
        return nums[min_index];
        // target과 가장 가까운 값 찾기
    }
    
private:
    void dfs(TreeNode* root, vector<int>& nums)
    {
        if (root == nullptr) {
            return;
        }
        nums.push_back(root->val);
        dfs(root->left, nums);
        dfs(root->right, nums);
    }
};