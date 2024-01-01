class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) 
    {
        size_t LEN = nums.size();
        int c = 0;

        for (size_t i = 0; i < LEN; ++i) {
            if (nums[i] % 2 == 0) {
                ++c;
            }
        }

        if (c > 1) {
            return true;
        }

        return false;
    }
};

// bit에 맨 마지막 자리가 1이 존재하면 홀수, 없으면 짝수
// 따라서 홀수만 없다면,  즉 짝수가 2개 이상이라면 무조건 true가 반환된다.



// https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/description/
