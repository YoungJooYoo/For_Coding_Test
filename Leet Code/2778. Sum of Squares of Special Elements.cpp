class Solution {
public:
    int sumOfSquares(vector<int>& nums) 
    {
        const size_t n = nums.size();
        int result = 0;

        for (size_t i = 0; i < n; ++i) {
            if (n % (i + 1) == 0) result += pow(nums[i], 2); 
        }

        return result;
    }
};

// https://leetcode.com/problems/sum-of-squares-of-special-elements/description/
