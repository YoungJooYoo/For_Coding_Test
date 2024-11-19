class Solution {
public:
    long long numberOfSubstrings(const string& s) 
    {
        vector<long long> freq(ALPHABET_LENGTH, 0);
        long long count = 0;

        for (const auto ch : s)
        {   
            const int INDEX = ch - 'a';
            ++freq[INDEX];
            count += freq[INDEX];
        }

        return count;
    }
private:
    enum { ALPHABET_LENGTH = 26 };
};

// https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/description/


/*

예제 1:
입력:

makefile
코드 복사
s = "abcba"
출력:

코드 복사
7
설명:

길이 1인 같은 문자로 시작하고 끝나는 부분 문자열: "a", "b", "c", "b", "a".
길이 3인 같은 문자로 시작하고 끝나는 부분 문자열: "bcb".
길이 5인 같은 문자로 시작하고 끝나는 부분 문자열: "abcba".
총 7개의 부분 문자열이 존재합니다.

예제 2:
입력:

makefile
코드 복사
s = "abacad"
출력:

코드 복사
9
설명:

길이 1인 같은 문자로 시작하고 끝나는 부분 문자열: "a", "b", "a", "c", "a", "d".
길이 3인 같은 문자로 시작하고 끝나는 부분 문자열: "aba", "aca".
길이 5인 같은 문자로 시작하고 끝나는 부분 문자열: "abaca".
총 9개의 부분 문자열이 존재합니다.

예제 3:
입력:

makefile
코드 복사
s = "a"
출력:

코드 복사
1
설명:

길이 1인 같은 문자로 시작하고 끝나는 부분 문자열: "a".
총 1개의 부분 문자열이 존재합니다.

제약 사항:
1 <= s.length <= 10^5
s는 오직 소문자 영어 문자로만 구성됩니다.
이 문제는 주어진 문자열에서 같은 문자로 시작하고 끝나는 모든 부분 문자열의 개수를 찾는 것이 목표입니다. 이를 위해 부분 문자열을 효율적으로 탐색하고 카운트하는 방법을 고려해야 합니다.
*/
