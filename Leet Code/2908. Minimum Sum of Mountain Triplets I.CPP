class Solution {
public:
    int minimumSum(vector<int>& nums) 
    {
        const size_t LEN = nums.size();
        int min_sum = INT_MAX;

        for (size_t i = 0; i < LEN - 2; ++i) {
            for (size_t j = i + 1; j < LEN - 1; ++j) {
                for (size_t k = j + 1; k < LEN; ++k) {
                    if (nums[i] < nums[j] and nums[k] < nums[j]) {
                        min_sum = min(min_sum, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }       

        if (min_sum == INT_MAX) {
            return NO_EXIST;
        }

        return min_sum;
    }

private:
    enum { NO_EXIST = - 1 };
};

// https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/
