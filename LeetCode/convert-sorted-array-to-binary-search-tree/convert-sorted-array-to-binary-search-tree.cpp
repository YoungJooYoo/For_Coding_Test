/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* solution(vector<int>& nums, int begin, int end) 
    {
        const int mid = (begin + end) / 2;
        if (begin > end) {
            return NULL;
        }
        
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = solution(nums, begin, mid - 1);
        node->right = solution(nums, mid + 1, end);
        
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        const size_t nums_length = nums.size() - 1;
        TreeNode* ans = solution(nums, 0, nums_length);
        
        return ans;
    }
};

/*

풀이법 :
주어진 배열은 이미 정렬이 되어있다. -> 분할정복 사용!!

*/