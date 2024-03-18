class Solution {
public:
    int sumOfEncryptedInt(const vector<int>& nums) 
    {
        int sum = 0;

        for (const auto& num : nums) {
            int number = num;
            int max_num = 0;
            int count = 0;
            while (number > 0) {
                max_num = max(max_num, number % 10);
                number /= 10;
                ++count;
            }
            int temp = 0;
            while (count-- != 0) {
                temp = (temp * 10) + max_num;
            }
            sum += temp;
        }

        return sum;
    }
};

// https://leetcode.com/problems/find-the-sum-of-encrypted-integers/description/
