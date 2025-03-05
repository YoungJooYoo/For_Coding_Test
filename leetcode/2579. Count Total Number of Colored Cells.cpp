class Solution 
{
public:
    long long coloredCells(const int n) const
    {
        return static_cast<long long>(2) * n * (n - 1) + 1;
    }
};

// https://leetcode.com/problems/count-total-number-of-colored-cells/description/?envType=daily-question&envId=2025-03-05
