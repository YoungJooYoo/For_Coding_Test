class Solution {
public:
    int countKDifference(vector<int>& nums, int k) 
    {
        const int ARR_SIZE = nums.size();
        int result = 0;

        for (size_t i = 0; i < ARR_SIZE - 1; ++i) {
            for (size_t j = i + 1; j < ARR_SIZE; ++j) {
                if (abs(nums[i] - nums[j]) == k) {
                    ++result;
                }
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/
