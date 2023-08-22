class Solution {
public:
    char repeatedCharacter(const string s) 
    {
        const size_t LEN = s.size();
        char hash[ALPGH_LEN] = { 0, };

        for (size_t i = 0; i < LEN; ++i) {
            int index = s[i] - 'a';
            ++hash[index];
            if (hash[index] == 2) return s[i];
        }

        return ' ';
    }

private:
    enum { ALPGH_LEN = 26 };
};

// https://leetcode.com/problems/first-letter-to-appear-twice/description/
