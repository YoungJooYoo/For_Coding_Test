class Solution 
{
public:
    int maxUniqueSplit(const string& s) 
    {
        return backTrackmaxUniqueSplit(s, 0);
    }

private:
    int backTrackmaxUniqueSplit(const string& s, const int start) 
    {
        if (start == s.size()) 
        {
            return 0;
        }

        int maxCount = 0;
        for (int end = start + 1; end <= s.size(); ++end) 
        {
            const string current = s.substr(start, end - start); //substr로 start+1로 시작
            if (mSubstr.find(current) == mSubstr.end()) 
            {
                mSubstr.insert(current);
                const int count = 1 + backTrackmaxUniqueSplit(s, end);
                maxCount = max(maxCount, count);
                mSubstr.erase(current);
            }
        }

        return maxCount;
    }

private:
    unordered_set<string> mSubstr;
};

// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/?envType=daily-question&envId=2024-10-21

/*
1593. 문자열을 최대 개수의 고유한 부분 문자열로 분할하기

📄 문제 설명
문자열 s가 주어집니다. 주어진 문자열을 고유한 부분 문자열의 최대 개수로 분할할 때, 그 개수를 반환하세요.

문자열 s는 비어 있지 않은 부분 문자열들의 리스트로 분할할 수 있으며, 이 부분 문자열들을 이어 붙인 결과는 원래의 문자열 s가 됩니다. 단, 모든 부분 문자열은 서로 달라야 합니다.

부분 문자열이란 문자열 내에서 연속된 문자들의 시퀀스를 의미합니다.

💡 예제 1:
less
코드 복사
입력: s = "ababccc"
출력: 5
설명: 최대한 분할하는 한 가지 방법은 ['a', 'b', 'ab', 'c', 'cc']입니다. ['a', 'b', 'a', 'b', 'c', 'cc']와 같이 분할하는 것은 'a'와 'b'가 여러 번 등장하므로 유효하지 않습니다.
💡 예제 2:
arduino
코드 복사
입력: s = "aba"
출력: 2
설명: 최대한 분할하는 한 가지 방법은 ['a', 'ba']입니다.
💡 예제 3:
makefile
코드 복사
입력: s = "aa"
출력: 1
설명: 문자열을 더 이상 분할할 수 없습니다.
📌 제약 사항:
1 <= s.length <= 16
s는 소문자 영어 알파벳만을 포함합니다.

*/
