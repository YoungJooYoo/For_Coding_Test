class Solution 
{
public:
    int mirrorDistance(const int n) const
    {
        assert(MIN_N <= n && n <= MAX_N);

        string number = to_string(n);
        ranges::reverse(number);
        const int num = stoi(number);

        return abs(num - n);
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = 1000000000
    };
};

// https://leetcode.com/problems/mirror-distance-of-an-integer/description/
