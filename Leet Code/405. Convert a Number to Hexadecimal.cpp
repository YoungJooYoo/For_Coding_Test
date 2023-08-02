class Solution {
public:
    string toHex(int num) 
    {
        if (num == 0) return "0";

         unsigned int number = num; // 비트패턴
         string result;
         int remainder;

        while (number != 0) {
            remainder = number % BASE_16;
            if (remainder < 10) {
                result += ('0' + remainder);
            }
            else {
                result += ('a' + (remainder % 10));
            }
            number /= BASE_16;
        }

        reverse(result.begin(), result.end());
        return result;
    }

private: 
    enum { BASE_16 = 16 };
};

// https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
