class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        long long left = 0;
        long long right = static_cast<long long>(sqrt(c));

        while(left <= right)
        {
            const long long sum = pow(left, 2) + pow(right, 2);
            if (sum == c)
            {
                return true;
            }
            else if (sum > c)
            {
                --right;
            }
            else
            {
                ++left;
            }
        }

        return false;
    }
};

// https://leetcode.com/problems/sum-of-square-numbers/description/?envType=daily-question&envId=2024-06-17
