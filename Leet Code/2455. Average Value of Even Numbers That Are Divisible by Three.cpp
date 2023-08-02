class Solution {
public:
    int averageValue(vector<int>& nums) 
    {
        int result = 0;
        int count = 0;

        for (const auto& num : nums) {
            if (num % 3 == 0 && num % 2 == 0) {
                result += num;
                ++count;
            }
        }

        if (count == 0) return 0;
        
        return result / count;
    }
};

// https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/description/
