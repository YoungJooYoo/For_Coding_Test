class Solution
{
public:
    int smallestIndex(const vector<int>& nums) const
    {
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (digitSum(nums[i]) == static_cast<int>(i))
            {
                return static_cast<int>(i);
            }
        }

        return FAIL;
    }

private:
    static inline int digitSum(const int value)
    {
        int sum = 0;
        int x = value;

        while (x > 0)
        {
            sum += x % 10;
            x /= 10;
        }
        
        return sum;
    }

private:
    enum
    {
        FAIL = -1
    };
};

// https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/description/
