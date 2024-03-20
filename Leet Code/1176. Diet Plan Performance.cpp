class Solution {
public:
    int dietPlanPerformance(const vector<int>& calories, const int k, const int lower, const int upper) 
    {
        const size_t ARRAY_LENGTH = calories.size();
        int result = 0;

        int sum = accumulate(calories.begin(), calories.begin() + k, 0);
        if (sum < lower) {
            result -= 1;
        }
        else if (sum > upper) {
            result += 1;
        }

        for (size_t i = k; i < ARRAY_LENGTH; ++i) {
            sum += (calories[i] - calories[i - k]);
            if (sum < lower) {
                result -= 1;
            }
            else if (sum > upper) {
                result += 1;
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/diet-plan-performance/description/
