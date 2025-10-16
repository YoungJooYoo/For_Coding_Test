class Solution 
{
public:
    bool scoreBalance(const string& s) const
    {
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);
        int totalSum = 0;
        int currentSum = 0;

        for (const auto ch :s)
        {
            assert('a' <= ch && ch <= 'z');
            totalSum += (ch - 'a' + 1);
        }

        for (const auto ch :s)
        {
            const int currentValue = ch - 'a' + 1;
            currentSum += currentValue;
            if (currentSum * 2 == totalSum)
            {
                return true;
            }
        }
        
        return false;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100
    };
};

// https://leetcode.com/problems/equal-score-substrings/description/

/*
3707. 동일한 점수의 부분 문자열
힌트
소문자 영문자로만 이루어진 문자열 s가 주어집니다.

문자열의 **점수(score)**는 그 문자열에 포함된 각 문자의 알파벳 순서 위치의 합으로 정의됩니다. 여기서 'a' = 1, 'b' = 2, ..., 'z' = 26입니다.

문자열을 두 개의 비어 있지 않은 부분 문자열 s[0..i]와 s[(i + 1)..(n - 1)]로 나눌 수 있는 인덱스 i가 존재하는지 판단하세요. 이때 두 부분 문자열의 점수가 같아야 합니다.

만약 그러한 분할이 존재하면 true를 반환하고, 그렇지 않으면 false를 반환하세요.

예시 1:

입력: s = "adcb"
출력: true
설명:
인덱스 i = 1에서 분할합니다.

왼쪽 부분 문자열 = s[0..1] = "ad", 점수 = 1 + 4 = 5
오른쪽 부분 문자열 = s[2..3] = "cb", 점수 = 3 + 2 = 5
두 부분 문자열의 점수가 같으므로 출력은 true입니다.
예시 2:

입력: s = "bace"
출력: false
설명:
어떤 인덱스로 분할해도 점수가 같은 두 부분 문자열을 만들 수 없습니다. 따라서 출력은 false입니다.

제약 조건:

2 <= s.length <= 100
s는 소문자 영문자로만 구성됩니다.
*/
