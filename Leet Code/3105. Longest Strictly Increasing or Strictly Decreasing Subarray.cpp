class Solution {
public:
    int longestMonotonicSubarray(const vector<int>& nums) 
    {
        const size_t ARRAY_LENGTH = nums.size();
        int max_length = 1;
        int increasing_length = 1;
        int decreasing_length = 1;

        for (size_t i = 1; i < ARRAY_LENGTH; ++i) {
            if (nums[i - 1] < nums[i]) {
                ++increasing_length;
                decreasing_length = 1;
            } 
            else if (nums[i - 1] > nums[i]) {
                ++decreasing_length;
                increasing_length = 1;
            } 
            else {
                increasing_length = 1;
                decreasing_length = 1;
            }
            max_length = max(max_length, max(increasing_length, decreasing_length));
        }

        return max_length;
    }
};

// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
