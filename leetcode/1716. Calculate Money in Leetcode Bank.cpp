class Solution {
public:
    int totalMoney(int n) 
    {
        int result = 0;
        int day = 1;

        while (n > 0) {
            for (size_t i = 0 ; i < WEEK && n-- > 0; ++i) {
                result += day + i;
            }
            ++day;
        }
        
        return result;
    }

private:
    enum { WEEK = 7 };
};

// https://leetcode.com/problems/calculate-money-in-leetcode-bank/
