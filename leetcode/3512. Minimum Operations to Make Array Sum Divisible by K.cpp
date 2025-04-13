class Solution 
{
public:
    int minOperations(const vector<int>& nums, const int k) const
    {
        int totalSum = accumulate(nums.begin(),nums.end(), 0);
        int result = 0;

        while (totalSum % k != 0)
        {
            --totalSum;
            ++result;
        }

        return result;
    }
};

// https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/
