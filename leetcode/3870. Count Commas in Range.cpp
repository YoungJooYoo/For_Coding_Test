class Solution
{
public:
    int countCommas(const int n) const
    {
        assert(MIN_N <= n && n <= MAX_N);
        return (n < MIN_COMMA_START) ? 0 : n - (MIN_COMMA_START - 1);
    }

private:
    enum
    {
        MIN_N           = 1,
        MAX_N           = 100000,
        MIN_COMMA_START = 1000,    // 쉼표가 처음 등장하는 숫자
    };
};

// https://leetcode.com/problems/count-commas-in-range/description/
