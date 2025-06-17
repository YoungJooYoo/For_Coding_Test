class Solution 
{
public:
    string generateTag(const string& caption) 
    {
        assert(MIN_LENGTH <= caption.size() && caption.size() <= MAX_LENGTH);

        string tag = "#";
        stringstream captionStream(caption);
        vector<string> wordList;
        string currentWord;

        while (getline(captionStream, currentWord, ' ')) // caption을 공백 기준으로 분할하여 단어 리스트 생성
        {
            if (!currentWord.empty())
            {
                wordList.push_back(currentWord);
            }
        }

        const size_t wordCount = wordList.size();
        for (size_t i = 0; i < wordCount; ++i)
        {
            string alphaOnlyWord;
            for (const char ch : wordList[i])    // 알파벳만 남김
            {
                if (isalpha(ch))
                {
                    alphaOnlyWord += ch;
                }
            }
            if (!alphaOnlyWord.empty())
            {
                if (i == 0) // 첫 글자 케이스 변환
                {
                    alphaOnlyWord[0] = tolower(alphaOnlyWord[0]);
                }
                else
                {
                    alphaOnlyWord[0] = toupper(alphaOnlyWord[0]);
                }
                
                for (size_t j = 1; j < alphaOnlyWord.size(); ++j) // 나머지 글자 소문자화
                {
                    alphaOnlyWord[j] = tolower(alphaOnlyWord[j]);
                }

                tag += alphaOnlyWord;
            }
        }

        if (tag.size() > MAX_RESULT_LENGTH)
        {
            tag = tag.substr(0, MAX_RESULT_LENGTH);
        }

        return tag;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 150,
        MAX_RESULT_LENGTH = 100,
    };
};

// https://leetcode.com/problems/generate-tag-for-video-caption/description/
