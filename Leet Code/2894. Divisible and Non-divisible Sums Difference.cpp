class Solution {
public:
    int differenceOfSums(const int n, const int m) 
    {
        int sum_n = 0;
        int sum_m = 0;

        for (int i = 1; i <= n; ++i) {
            if (i % m  == 0) sum_m += i;
            else sum_n += i;
        }

        return sum_n - sum_m;
    }
};

// https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/description/
