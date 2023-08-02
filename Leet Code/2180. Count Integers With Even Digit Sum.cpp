class Solution {
public:
    int countEven(int num) 
    {
        int count = 0;

        for (size_t i = 2; i <= num; ++i) {
            int temp = i;
            int sum = 0;
            while (temp != 0) { // 자리수 분리하여 더하기
                sum += (temp % 10);
                temp /= 10;
            }
            if (sum % 2 == 0) ++ count;
        }

        return count;
    }
};

// https://leetcode.com/problems/count-integers-with-even-digit-sum/description/
