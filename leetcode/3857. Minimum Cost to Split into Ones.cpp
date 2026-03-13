class Solution 
{
public:
    int minCost(int n) const
    {
        assert(MIN_N <= n && n <= MAX_N);
        return (n * (n - 1)) / 2;
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = 500,
    };
};

// https://leetcode.com/problems/minimum-cost-to-split-into-ones/description/
