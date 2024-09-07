class Solution 
{
public:
    string stringHash(const string& s, const int k) 
    {
        const size_t LENGTH = s.size();
        string result;

        for (size_t i = 0; i <= LENGTH - k; i = i + k)
        {
            int hashValue = 0;
            for (size_t j = i; j < i + k; ++j)
            {
                hashValue += s[j] - 'a';
            }
            hashValue %= ALPHABET_LENGTH;
            result.push_back(hashValue + 'a');
        }

        return result;
    }

private:
    enum { ALPHABET_LENGTH = 26 };
};

// https://leetcode.com/problems/hash-divided-string/description/

/*
3271. 문자열을 해시로 분할 난이도: 중간 주제 힌트 길이가 n이고 정수 k가 주어진 문자열 s가 있습니다. 여기서 n은 k의 배수입니다. 문자열 s를 길이가 n / k인 새로운 문자열인 result로 해시하는 작업을 수행해야 합니다.

먼저, s를 길이가 k인 n / k개의 부분 문자열로 나눕니다. 그리고 result를 빈 문자열로 초기화합니다.

시작부터 차례대로 각 부분 문자열에 대해:

문자의 해시 값은 영어 알파벳에서 그 문자의 인덱스입니다 (예: 'a' → 0, 'b' → 1, ..., 'z' → 25). 부분 문자열의 문자들에 대한 해시 값의 합을 계산합니다. 이 합을 26으로 나눈 나머지를 hashedChar라고 합니다. hashedChar에 해당하는 영어 소문자 알파벳 문자를 식별합니다. 그 문자를 result의 끝에 추가합니다. result를 반환합니다.

예제 1:

입력: s = "abcd", k = 2

출력: "bf"

설명:

첫 번째 부분 문자열: "ab", 0 + 1 = 1, 1 % 26 = 1, result[0] = 'b'.

두 번째 부분 문자열: "cd", 2 + 3 = 5, 5 % 26 = 5, result[1] = 'f'.

예제 2:

입력: s = "mxz", k = 3

출력: "i"

설명:

유일한 부분 문자열: "mxz", 12 + 23 + 25 = 60, 60 % 26 = 8, result[0] = 'i'.

제한 사항:

1 <= k <= 100 k <= s.length <= 1000 s의 길이는 k의 배수입니다. s는 소문자 영어 문자로만 구성됩니다.

*/
