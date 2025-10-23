class Solution 
{
public:
    string findCommonResponse(const vector<vector<string>>& responses) const
    {
        assert(!responses.empty());
        assert(responses.size() >= MIN_RESPONSES && responses.size() <= MAX_RESPONSES);

        map<string, int> freq;
        int maxFreq = 0;

        for (const vector<string>& response : responses)
        {
            assert(response.size() >= MIN_WORDS && response.size() <= MAX_WORDS);
            set<string> uniqueWords;
            for (const string& word : response)
            {
                assert(!word.empty());
                assert(word.size() >= MIN_WORD_LEN && word.size() <= MAX_WORD_LEN);
                uniqueWords.insert(word);
            }
            for (const string& word : uniqueWords)
            {
                ++freq[word];
                maxFreq = max(maxFreq, freq[word]);
            }
        }

        for (const auto& [word, count] : freq)
        {
            if (count == maxFreq)
            {
                return word;
            }
        }

        return "";
    }

private:
    enum
    {
        MIN_RESPONSES = 1,
        MAX_RESPONSES = 1000,
        MIN_WORDS = 1,
        MAX_WORDS = 1000,
        MIN_WORD_LEN = 1,
        MAX_WORD_LEN = 10
    };
};

// https://leetcode.com/problems/find-the-most-common-response/description/
