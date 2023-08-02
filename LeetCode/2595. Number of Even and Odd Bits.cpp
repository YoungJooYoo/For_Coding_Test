class Solution {
public:
    vector<int> evenOddBit(int n) 
    {
        vector<int> binary;
        vector<int> result(2, 0);

        while (n != 0) {
            if (n % 2 == 0) {
                binary.push_back(0);
            }
            else {
                 binary.push_back(1);
            }
            n /= 2;
        }

        for (size_t i = 0; i < binary.size(); ++i) {
            if (i % 2 == 0 && binary[i] == 1) {
                ++result[0];
            }
            else if (i % 2 == 1 && binary[i] == 1) {
                ++result[1];
            }
        }

        return result;
    }
};

https://leetcode.com/problems/number-of-even-and-odd-bits/description/
