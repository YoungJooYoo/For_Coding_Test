class Solution 
{
public:
    int gcdOfOddEvenSums(const int n) const 
    {
        assert(MIN_N <= n && n <= MAX_N);

        int sumOdd = 0;
        int sumEven = 0;

        for (int i = 0; i < n; ++i)
        {
            sumOdd += (2 * i) + 1;
            sumEven += (2 * i);
        }
        
        return __gcd(sumOdd, sumEven);
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = 1000
    };
};

// https://leetcode.com/problems/gcd-of-odd-and-even-sums/description/
