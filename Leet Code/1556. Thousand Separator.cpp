class Solution {
public:
    string thousandSeparator(int n) 
    {
        string result;
        int count = 0;

        if (n == 0) {
            result.push_back('0');
            return result;
        }

        while (n != 0) {
            result.push_back((n % 10) + '0');
            n /= 10;
            if (++count % 3 == 0 && n != 0) {
                result.push_back('.');
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

// https://leetcode.com/problems/thousand-separator/description/
