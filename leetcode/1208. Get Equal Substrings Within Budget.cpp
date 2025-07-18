class Solution
{
public:
    int equalSubstring(const string& s, const string& t, const int maxCost) const
    {
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);
        assert(s.size() == t.size());
        assert(MIN_COST <= maxCost && maxCost <= MAX_COST);

        const size_t length = s.size();
        size_t left = 0;
        int currCost = 0;
        int maxLen = 0;

        for (size_t right = 0; right < length; ++right)
        {
            assert(MIN_CHAR <= s[right] && s[right] <= MAX_CHAR);
            assert(MIN_CHAR <= t[right] && t[right] <= MAX_CHAR);
            currCost += abs(s[right] - t[right]);
            while (currCost > maxCost)
            {
                currCost -= abs(s[left] - t[left]);
                ++left;
            }
            const int currLen = static_cast<int>(right - left + 1);
            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000,
        MIN_COST = 0,
        MAX_COST = 1000000,
        MIN_CHAR = 'a',
        MAX_CHAR = 'z'
    };
};

// https://leetcode.com/problems/get-equal-substrings-within-budget/description/?envType=problem-list-v2&envId=string
