class Solution {
public:
    int missingInteger(vector<int>& nums) 
    {
        const size_t LEN = nums.size();
        int result = 0;
        int prefix_sum = nums[0];

        for (size_t i = 1; i < LEN; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                prefix_sum += nums[i];
            }
            else break;
        }

        sort(nums.begin(),nums.end());
            
        for (size_t i = 0; i < LEN; ++i) {
            if (prefix_sum == nums[i]) ++prefix_sum;
        }

        return prefix_sum;
    }
};

// https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/description/
