class Solution {
public:
    string replaceDigits(string s) 
    {
        const size_t LEN = s.size();

        for (size_t i = 1; i < LEN; i = i + 2) {
            if ('0' <= s[i] && s[i] <= '9') {
                int index = s[i] - '0';
                s[i] = s[i - 1] + index;
            }
        }

        return s;
    }
};

https://leetcode.com/problems/replace-all-digits-with-characters/description/
