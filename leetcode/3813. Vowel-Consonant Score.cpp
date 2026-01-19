class Solution 
{
public:
    int vowelConsonantScore(const string& s) const
    {
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);
        int vowelCount = 0;
        int consonantCount  = 0;

        for (const auto ch : s)
        {
            assert(('a' <= ch && ch <= 'z') or (ch == ' ') or ('0' <= ch && ch <= '9'));
            if (HasVowel(ch) == true)
            {
                ++vowelCount;
            }
            else if (isalpha(ch))
            {
                ++consonantCount;
            }
        }

        return (consonantCount) == 0 ? 0 : (vowelCount / consonantCount);
    }

private:
    inline bool HasVowel(const char ch) const
    {
        if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u')
        {
            return true;
        }
        
        return false;
    }

    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
    };
};

// https://leetcode.com/problems/vowel-consonant-score/description/
