class Solution {
public:
    int minimumSum(int num) 
    {
        int nums[SIZE];

        size_t i = 0;
        while(num != 0) {
            nums[i++] = num % 10;
            num /= 10;
        }
        sort(begin(nums), end(nums));
        
        return 10 * (nums[0] + nums[1]) + nums[2] + nums[3]; // 정렬 후 최저 숫자 2자리가 10의 자리 숫자가 되는데 좋다.
    }

private:
    enum { SIZE = 4 };
};

// https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/description/
