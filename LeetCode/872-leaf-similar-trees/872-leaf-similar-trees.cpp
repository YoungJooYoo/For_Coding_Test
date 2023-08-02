class Solution {
public:
    void dfs(TreeNode* root, vector<int>& nums)
    {
        if (root == nullptr) {
            return;
        }
        
        // leaf노드 방문시에만 배열에 넣는다.
        if (root->left == nullptr && root->right == nullptr) {
            nums.push_back(root->val);
        }
        
        dfs(root->left, nums);
        dfs(root->right, nums);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> nums1;
        vector<int> nums2;
        
        dfs(root1, nums1);
        dfs(root2, nums2);
    
        if (nums1.size() != nums2.size()) {
            return false;
        }
        for (size_t i = 0; i < nums1.size(); i++) {
            if (nums1[i] != nums2[i]) {
                return false;
            }
        }
        
        return true;
    }
};

/*
풀이법 :
leaf방문한 것을 배열에 넣는다.
그리고 두 배열을 배교해서
길이가 다르거나, 값이 다르면 false를 반환
*/