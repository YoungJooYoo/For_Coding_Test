
class Solution 
{
public:
    int findDerangement(const int n) const 
    {
        assert(MIN_N <= n && n <= MAX_N);
        
        if (n == 1) 
        {
            return 0;
        }
        else if (n == 2) 
        {
            return 1;
        }
        
        long long prev2 = 0;  // D(i-2)
        long long prev1 = 1;  // D(i-1)
        long long curr = 0;
        
        for (long long i = 3; i <= n; ++i) 
        {
            curr = (i - 1) * (prev1 + prev2) % MODULO;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return static_cast<int>(curr);
    }

private:
    enum 
    {
        MODULO = 1000000000 + 7,
        MIN_N   = 1,
        MAX_N   = 1000000
    };
};

// https://leetcode.com/problems/find-the-derangement-of-an-array/description/
