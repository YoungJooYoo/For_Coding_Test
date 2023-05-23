class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) 
    {
        vector<int> divisibilities;
        int max_divisor = divisors[0];
        int max_count = 0;
        
        for (const auto& divisor : divisors) {
            int count = 0;
            for (const auto& num : nums) {
                if (num % divisor == 0) ++count;
            }
            if (count > max_count) {
                max_count = count;
                max_divisor = divisor;
            }
            else if (count == max_count) {
                if (max_divisor > divisor) {
                    max_divisor = divisor;
                }
            }
        }
        
         
        return max_divisor;
    }
};

// https://leetcode.com/problems/find-the-maximum-divisibility-score/
