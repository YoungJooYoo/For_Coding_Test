class Solution
{
public:
    int numberOfSpecialChars(const string& word) const
    {
        assert(MIN_LENGTH <= static_cast<int>(word.size()) && static_cast<int>(word.size()) <= MAX_LENGTH);

        // 각 알파벳의 마지막 소문자 인덱스, 첫 번째 대문자 인덱스 저장
        vector<int> lastLowerIndex(ALPHABET_SIZE, -1);
        vector<int> firstUpperIndex(ALPHABET_SIZE, INT_MAX);

        for (size_t i = 0; i < word.size(); ++i)
        {
            const char ch = word[i];
            assert(isalpha(ch) != 0);
            if (islower(ch) != 0)
            {
                const int alphabetIndex = ch - 'a';
                lastLowerIndex[alphabetIndex] = static_cast<int>(i);
            }
            else
            {
                const int alphabetIndex = ch - 'A';
                firstUpperIndex[alphabetIndex] = min(firstUpperIndex[alphabetIndex], static_cast<int>(i));
            }
        }

        // 모든 소문자가 첫 대문자보다 앞에 있는지 확인
        int specialCount = 0;
        for (size_t i = 0; i < ALPHABET_SIZE; ++i)
        {
            if (lastLowerIndex[i] == NOT_FOUND)
            {
                continue;
            }
            if (firstUpperIndex[i] == INT_MAX)
            {
                continue;
            }
            if (lastLowerIndex[i] < firstUpperIndex[i])
            {
                ++specialCount;
            }
        }

        return specialCount;
    }

private:
    enum
    {
        MIN_LENGTH    = 1,
        MAX_LENGTH    = 200000,
        ALPHABET_SIZE = 26,
        NOT_FOUND     = -1,
    };
};

// https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/
