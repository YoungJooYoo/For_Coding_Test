class Solution
{
public:
    string majorityFrequencyGroup(const string& s) const
    {
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);

        map<int, string, greater<int>> countToChars;
        unordered_map<char, int> freq;
        string maxString;
        int maxLength = 0;

        for (const char ch : s)
        {
            assert('a' <= ch && ch <= 'z');
            ++freq[ch];
        }

        for (int i = MIN_LENGTH; i <= MAX_LENGTH; ++i)
        {
            for (const auto& [ch, count] : freq)
            {
                if (count == i)
                {
                    countToChars[i].push_back(ch);
                    ranges::sort(countToChars[i]);
                    if (maxLength <= countToChars[i].size())
                    {
                        maxLength = countToChars[i].size();
                        maxString = countToChars[i];
                    }
                }
            }
        }

        return maxString;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100
    };
};

// https://leetcode.com/problems/majority-frequency-characters/description/
