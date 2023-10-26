class Solution {
public:
    int alternateDigitSum(const int n) 
    {
        const string nums = to_string(n);
        int sum = 0;
        
        for (size_t i = 0; i < nums.size(); ++i) {
            const int temp = nums[i] - '0';
            if (i % 2 == 0) {
                sum += temp;
            }
            else {
                sum += (temp * -1);
            }
        }

        return sum;
    }
};

// https://leetcode.com/problems/alternating-digit-sum/description/
