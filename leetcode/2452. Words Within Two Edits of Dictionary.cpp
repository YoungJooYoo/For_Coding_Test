class Solution
{
public:
    vector<string> twoEditWords(const vector<string>& queries, const vector<string>& dictionary) const
    {
        assert(MIN_LENGTH <= static_cast<int>(queries.size()) && static_cast<int>(queries.size()) <= MAX_LENGTH);
        assert(MIN_LENGTH <= static_cast<int>(dictionary.size()) && static_cast<int>(dictionary.size()) <= MAX_LENGTH);

        const size_t wordLength = dictionary[0].size();
        vector<string> result;

        for (const auto& query : queries)
        {
            assert(query.size() == wordLength);
            for (const auto& word : dictionary)
            {
                assert(word.size() == wordLength);
                if (isTwoEditWord(query, word) == true)
                {
                    result.push_back(query);
                    break;
                }
            }
        }

        assert(static_cast<int>(result.size()) <= static_cast<int>(queries.size()));
        return result;
    }

private:
    bool isTwoEditWord(const string& query, const string& word) const
    {
        assert(query.size() == word.size());
        assert(MIN_WORD_LENGTH <= static_cast<int>(query.size()) && static_cast<int>(query.size()) <= MAX_WORD_LENGTH);

        const size_t wordLength = query.size();
        int diffCount = 0;

        for (size_t i = 0; i < wordLength; ++i)
        {
            assert(islower(query[i]) && islower(word[i]));
            if (query[i] != word[i])
            {
                ++diffCount;
            }

            if (diffCount > MAX_EDIT_COUNT)
            {
                return false;
            }
        }

        return (diffCount <= MAX_EDIT_COUNT) ? true : false;
    }

    enum
    {
        MIN_LENGTH      = 1,
        MAX_LENGTH      = 100,
        MIN_WORD_LENGTH = 1,
        MAX_WORD_LENGTH = 100,
        MAX_EDIT_COUNT  = 2,
    };
};
