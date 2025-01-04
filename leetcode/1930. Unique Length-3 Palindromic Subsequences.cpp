class Solution 
{
public:
    int countPalindromicSubsequence(const string& inputString) 
    {
        array<int, ALPHABET_COUNT> firstIndex;
        array<int, ALPHABET_COUNT> lastIndex;
        const size_t LENGTH = inputString.size();
        int result = 0;

        firstIndex.fill(numeric_limits<int>::max()); // 첫 번째 인덱스를 최댓값으로 초기화
        for (size_t i = 0; i < LENGTH; ++i) // 알파벳이 처음 등장한 위치와, 마지막 등장하는 위치 찾기
        {
            const int charIndex = inputString[i] - 'a';
            firstIndex[charIndex] = min(firstIndex[charIndex], static_cast<int>(i));
            lastIndex[charIndex] = static_cast<int>(i);
        }

        // 각 문자에 대해 고유한 가운데 문자를 세기
        for (int charIndex = 0; charIndex < ALPHABET_COUNT; ++charIndex) 
        {
            if (firstIndex[charIndex] < lastIndex[charIndex]) 
            {
                const unordered_set<char> uniqueMiddleChars(
                    inputString.begin() + firstIndex[charIndex] + 1,
                    inputString.begin() + lastIndex[charIndex]
                );
                result += static_cast<int>(uniqueMiddleChars.size());
            }
        }

        return result;
    }

private:
    enum : int 
    {
        ALPHABET_COUNT = 26 // 알파벳 수
    };
};

// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2025-01-04
