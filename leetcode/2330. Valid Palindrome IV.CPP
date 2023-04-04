class Solution {
public:
    bool makePalindrome(string s) 
    {
        int i = 0;
        int j = s.size() - 1;
        size_t count = 0;

        while (i < j) {
            if (s[i] != s[j]) {
                count++;
                if (count >= MAX_CHAGE_COUNT) {
                    return false;
                }
            }
            ++i;
            --j;
        }

        return true;
    }

private:
    enum { MAX_CHAGE_COUNT = 3 };
};

// https://leetcode.com/problems/valid-palindrome-iv/description/
