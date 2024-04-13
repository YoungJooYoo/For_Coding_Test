class Solution {
public:
    int minBitFlips(const int start, const int goal) 
    {
        int xor_num = start ^ goal;
        int count = 0;

        while (xor_num != 0) {
            const int temp = xor_num % 2;
            if (temp == 1) ++count;
            xor_num /= 2;
        }

        return count;
    }
};

// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
