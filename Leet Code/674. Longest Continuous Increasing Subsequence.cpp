class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int count = 1;
        int result = 1;

        int prev = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (prev < nums[i]) {
                ++count;
                prev = nums[i];
            }
            else {
                result = max(result, count);
                count = 1;
                prev = nums[i];
            }
        }

        return max(result, count); 
    }
};

// https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
