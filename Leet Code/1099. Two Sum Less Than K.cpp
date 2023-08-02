class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) 
    {
        const size_t LENGTH = nums.size();
        int result = -1;

        for (size_t i = 0; i < LENGTH; ++i) {
            for (size_t j = i + 1; j < LENGTH; ++j) {
                int temp = nums[i] + nums[j];
                if (temp < k) {
                    result = max(result, temp);
                }
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/two-sum-less-than-k/description/
