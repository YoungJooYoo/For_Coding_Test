class Solution 
{
public:
    string trimTrailingVowels(const string& s) const
    {
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);

        const size_t LENGTH = s.size();
        bool isTrailing = true;
        string result = "";

        for (int i = static_cast<int>(LENGTH) - 1; i >= 0; --i)
        {
            assert('a' <= s[i] && s[i] <= 'z');
            if (isTrailing == true && isVowel(s[i]) == true)
            {
                continue;
            }
            else
            {
                isTrailing = false; 
                result.push_back(s[i]);
            }
        }

        ranges::reverse(result);
        return result;
    }

private:
    bool isVowel(const char ch) const
    {
        if (ch == 'a' or ch =='e' or ch == 'i' or ch == 'o' or ch == 'u')
        {
            return true;
        }

        return false;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100
    };
};

// https://leetcode.com/problems/trim-trailing-vowels/description/
