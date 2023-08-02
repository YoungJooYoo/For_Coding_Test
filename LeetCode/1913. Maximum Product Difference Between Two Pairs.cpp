class Solution {
public:
    int maxProductDifference(vector<int>& nums) 
    {
        const size_t last_index = nums.size() - 1;
        sort(nums.begin(), nums.end());

        return (nums[last_index] * nums[last_index -1 ]) - (nums[0] * nums[1]);
    }
};

// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/
