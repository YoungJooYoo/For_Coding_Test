class Solution {
public:
    int numberOfSpecialChars(const string& word) 
    {
        set<char> uppercase;
        set<char> lowercase;
        int count = 0;

        for (const auto& ch : word) {
            if ('a' <= ch && ch <= 'z') {
                lowercase.insert(ch);
            }
            else {
                uppercase.insert(ch);
            }
        }

        for (const auto& ch : uppercase) {
            const char lower_char = ch + 32;
            if (lowercase.find(lower_char) != lowercase.end()) {
                ++count;
            };
        }

        return count;
    }
};

// https://leetcode.com/problems/count-the-number-of-special-characters-i/description/
