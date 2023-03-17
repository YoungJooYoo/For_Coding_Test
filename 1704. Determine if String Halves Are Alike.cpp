class Solution {
public:
    bool is_vowel(const char ch) 
    {
        for (const auto& vo : vowel) {
            if (ch == vo) {
                return true;
            }
        }

        return false;
    }

    bool halvesAreAlike(string s) 
    {
        size_t SIZE = s.size();
        size_t vowel_1 = 0;
        size_t vowel_2 = 0;

        for (size_t i = 0; i < SIZE / 2; ++i) {
            if (is_vowel(s[i])) vowel_1++;
        }
        for (size_t i = SIZE / 2; i <= SIZE; ++i) {
            if (is_vowel(s[i])) vowel_2++;
        }

        return vowel_1 == vowel_2 ? true : false;
    }

private:
    string vowel = "aeiouAEIOU";
};

// https://leetcode.com/problems/determine-if-string-halves-are-alike/description/
