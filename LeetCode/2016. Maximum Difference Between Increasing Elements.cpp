class Solution {
public:
    int maximumDifference(vector<int>& nums) 
    {
        const size_t n = nums.size();
        int max_val = 0;

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                if (i < j && nums[j] - nums[i] > max_val) {
                    max_val = nums[j] - nums[i];
                }
            }
        }

        return max_val == 0 ? -1 : max_val;     
    }
};

// https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/
