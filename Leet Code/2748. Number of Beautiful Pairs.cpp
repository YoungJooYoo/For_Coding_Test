class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) 
    {
        const size_t LEN = nums.size();
        int result = 0;

        for (size_t i = 0; i < LEN; ++i) {
            for (size_t j = i + 1; j < LEN; ++j) {
                const int first_num = to_string(nums[i])[0] - '0';
                const int last_num = nums[j] % 10;
                const int divisor = __gcd(first_num, last_num);
                if (divisor == 1) {
                    ++result;
                }
            }
        }

        return result;    
    }
};

/*
nums[i]의 첫 번째 숫자와 nums[j]의 마지막 숫자가 서로 소수(coprime)이면 이것을 아름다운 쌍이라고 합니다.
*/

// https://leetcode.com/problems/number-of-beautiful-pairs/description/
