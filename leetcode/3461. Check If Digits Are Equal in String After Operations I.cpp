class Solution 
{
public:
    bool hasSameDigits(string &s) const
    {
        while (s.size() != TARGET_SIZE)
        {
            string nextDigits;
            for (size_t pos = 0; pos < s.size() - 1; ++pos)
            {
                const int digitSum = (((s[pos] - '0') + (s[pos + 1] - '0'))) % 10;
                nextDigits.push_back(digitSum + '0');
            }
            s = move(nextDigits);
        }

        return (s[0] == s[1]) ? true : false;
    }

private:
    enum
    {
        TARGET_SIZE = 2,
        MIN_LENGTH = 3,
        MAX_LENGTH = 100,
    };
};

// https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/
