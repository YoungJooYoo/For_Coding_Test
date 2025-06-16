class Solution 
{
public:
    int countOddLetters(const int n) const
    {
        assert(MIN_NUM <= n && n <= MAX_NUM);

        const string numStr = to_string(n);
        unordered_map<char, int> letterFrequency;
        int oddLetterCount = 0;

        for (const char digitChar : numStr)
        {
            const size_t digitIdx = digitChar - '0';
            const string& word = DIGIT_WORDS[digitIdx];
            for (const char letter : word)
            {
                ++letterFrequency[letter];
            }
        }

        for (const auto& [letter, freq] : letterFrequency)
        {
            if (freq % 2 == 1)
            {
                ++oddLetterCount;
            }
        }

        return oddLetterCount;
    }

private:
    static const vector<string> DIGIT_WORDS;

    enum
    {
        MIN_NUM = 1,
        MAX_NUM = 1000000000,
    };
};

const vector<string> Solution::DIGIT_WORDS =
{
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine"
};

// https://leetcode.com/problems/count-odd-letters-from-number/description/
