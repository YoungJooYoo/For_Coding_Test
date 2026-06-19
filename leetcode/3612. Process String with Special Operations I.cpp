class Solution
{
public:
    string processStr(const string& s) const
    {
        assert(MIN_LENGTH <= static_cast<int>(s.size()) && static_cast<int>(s.size()) <= MAX_LENGTH);
        string result;

        for (const char ch : s)
        {
            assert(islower(ch) != 0 || ch == STAR || ch == HASH || ch == PERCENT);
            if (islower(ch))
            {
                result += ch;
            }
            else if (ch == STAR)
            {
                if (result.empty() == false)
                {
                    result.pop_back();
                }
            }
            else if (ch == HASH)
            {
                result += result;
            }
            else if (ch == PERCENT)
            {
                ranges::reverse(result);
            }
            else
            {
                assert(false);
            }
        }

        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 20,
    };

    inline static const char STAR    = '*';
    inline static const char HASH    = '#';
    inline static const char PERCENT = '%';
};


// https://leetcode.com/problems/process-string-with-special-operations-i/description/?envType=daily-question&envId=2026-06-16
