class Solution {
public:
    int countDigits(int num) 
    {
        string nums = to_string(num);
        int result = 0;

        for (const auto& val : nums) {
            if (num % (val - '0') == 0) ++result;
        }

        return result;
    }
};

// https://leetcode.com/problems/count-the-digits-that-divide-a-number/description/
