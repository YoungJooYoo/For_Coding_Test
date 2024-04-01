class Solution {
public:
    bool isThree(const int n) 
    {
        int count = 2; // 1 and  n already diveded

        for (int i = 2; i < n; ++i) {
            if (n % i == 0) ++ count;
        }

        return count == 3 ? true : false;
    }
};

// https://leetcode.com/problems/three-divisors/description/
