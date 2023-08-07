class Solution {
public:
    string makeSmallestPalindrome(string s) 
    {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                int temp = min(s[i], s[j]);
                s[i] = (char)temp;
                s[j] = (char)temp;
            }
            ++i;
            --j;
        }

        return s;    
    }
};

// https://leetcode.com/problems/lexicographically-smallest-palindrome/description/
