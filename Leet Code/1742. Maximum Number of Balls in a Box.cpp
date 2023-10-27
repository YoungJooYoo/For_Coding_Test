class Solution {
public:
    const int digitSum (int n) const
    {
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n  /= 10;
        }

        return sum;
    }

    int countBalls(int lowLimit, int highLimit) 
    {
        unordered_map<int, int> mp;
        int max_val = INT_MIN;

        while (lowLimit <= highLimit) {
            const int index = digitSum(lowLimit);
            ++mp[index];
            ++lowLimit;
        }

        for (const auto& x : mp) {
            max_val = max(max_val, x.second);
        }

        return max_val;
    }
};

// https://leetcode.com/problems/maximum-number-of-balls-in-a-box/description/
