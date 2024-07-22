class Solution 
{
public:
    int minChanges(int n, int k) 
    {
        k ^= n;
        const int cnt = __builtin_popcount(k);
        k &= n;
        
        return (cnt == __builtin_popcount(k)) ? cnt : -1;
    }
};

// https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/description/
