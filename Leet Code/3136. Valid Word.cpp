class Solution {
public:
    bool isValid(const string& word) 
    {
        // 1. 단어의 길이가 3 이상인지 확인
        if (word.size() < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (const char ch : word) {
            // 2. 영어 문자 확인
            if (!isEnglishCharacter(ch)) return false;

            // 3. 모음 확인
            if (isVowel(ch)) hasVowel = true;

            // 4. 자음 확인
            if (isConsonant(ch)) hasConsonant = true;
        }

        // 5. 최소 하나의 모음과 자음이 있는지 확인
        return hasVowel && hasConsonant;
    }

private:
    // 영어 문자인지 확인하는 함수
    bool isEnglishCharacter(const char ch) const
    {
        return isalpha(ch) || isdigit(ch);
    }

    // 모음을 확인하는 함수
    bool isVowel(char ch) 
    {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    // 자음을 확인하는 함수
    bool isConsonant(char ch) 
    {
        ch = tolower(ch);
        return isalpha(ch) && !isVowel(ch);
    }
};

// https://leetcode.com/problems/valid-word/
