class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) 
    {
        const size_t LEN = nums.size();
        int result = INT_MIN;

        for (size_t i = 0; i  < LEN; ++i) {
            for (size_t j  = i; j  < LEN; ++j) {
                if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j])) {
                    result = max(result, nums[i] ^ nums[j]);
                }
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/maximum-strong-pair-xor-i/description/
