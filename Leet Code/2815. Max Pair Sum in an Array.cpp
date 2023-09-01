class Solution {
public:
    int is_pair(int num) // 자리수 세기
    {
        int pair = 0;

        while (num > 0) {
            pair = max(pair, num % 10);
            num /= 10;
        }

        return pair;
    }

    int maxSum(vector<int>& nums) 
    {
        const size_t LEN = nums.size();
        int result = -1;

        for (size_t i = 0; i < LEN; ++i) {
            for (size_t j = i + 1; j < LEN; ++j) {
                if (is_pair(nums[i]) == is_pair(nums[j])) {
                    result = max(result, nums[i] + nums[j]);
                }
            }
        }

        return result;    
    }
};

// https://leetcode.com/problems/max-pair-sum-in-an-array/
