class Solution 
{
public:
    int minimumOperations(vector<int>& nums) 
    {
        vector<long long> longNums(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int count = 0;

        while (left < right)
        {
            if (longNums[left] < longNums[right])
            {
                longNums[left + 1] += longNums[left];
                ++left;
                ++count;
            }
            else if (longNums[left] > longNums[right])
            {
                longNums[right - 1] += longNums[right];
                --right;
                ++count;
            }
            else
            {
                ++left;
                --right;
            }
        }

        return count;
    }
};

// https://leetcode.com/problems/merge-operations-to-turn-array-into-a-palindrome/
