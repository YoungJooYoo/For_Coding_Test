class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) 
    {
        double tax = 0;
        int prev = 0;

        for (const auto& bracket : brackets) {
            int actual = min(bracket[0], income);
            tax += ((actual - prev) * bracket[1] * 1.0) / 100.0;
            if (bracket[0] >= income) break;
            prev = bracket[0];
        }

        return tax;
    }
};

// https://leetcode.com/problems/calculate-amount-paid-in-taxes/description/
