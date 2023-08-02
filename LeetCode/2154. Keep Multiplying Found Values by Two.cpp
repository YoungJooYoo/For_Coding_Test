class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        sort(nums.begin(), nums.end());

        for (const auto& num : nums) {
            if (original == num) original *= 2;
        }

        return original;
    }
};

// https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/
