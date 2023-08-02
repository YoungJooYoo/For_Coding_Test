class Solution {
public:
    string reverseOnlyLetters(string s) 
    {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (!(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))) {
                ++i;
                continue;
            }
            if (!(('a' <= s[j] && s[j] <= 'z') || ('A' <= s[j] && s[j] <= 'Z'))) {
                --j;
                continue;
            }
            swap(s[i], s[j]);
            ++i;
            --j;
        }

        return s;
    }
};

https://leetcode.com/problems/reverse-only-letters/description/
