class Solution 
{
public:
    string compressedString(const string& word) 
    {
        const size_t LENGTH = word.size();
        string result;
        char currentChar = word[0];
        int currentLength = 0;

        // 실시간으로 길이를 확인 9개 단위로 잘라서 저장
        for (size_t i = 0; i < LENGTH; ++i)
        {
            if (currentChar == word[i])
            {
                ++currentLength;
                if (currentLength == MAX_LENGTH) // 중간중간 9개인지 체크후 저장하기
                {
                    result += to_string(currentLength);
                    result += currentChar;
                    currentLength = 0;
                }
            }
            else // 단어가 바뀌는 순간, 저장 후, 변수들을 초기화
            {
                if (currentLength != 0)
                {
                    result += to_string(currentLength);
                    result += currentChar;
                    currentLength = 0;
                }
                ++currentLength;
                currentChar = word[i];
            }
        }
        if (currentLength != 0) // the last thing
        {
            result += to_string(currentLength);
            result += currentChar;
        }
        
        return result;        
    }

private:
    enum { MAX_LENGTH = 9 };
};

// https://leetcode.com/problems/string-compression-iii/description/
