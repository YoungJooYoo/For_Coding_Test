class Solution
{
public:
    int minLengthAfterRemovals(const string& s) const
    {
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);

        int balance = 0;

        for (const char ch : s)
        {
            assert(ch == 'a' || ch == 'b');
            if (ch == 'a')
            {
                ++balance;
            }
            else // ch == 'b'
            {
                --balance;
            }
        }

        return abs(balance);
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000
    };
};


// https://leetcode.com/problems/minimum-string-length-after-balanced-removals/description/

/*
746. 균형 잡힌 제거 후 최소 문자열 길이
힌트
소문자 'a'와 'b'로만 구성된 문자열 s가 주어집니다.

당신은 'a' 문자의 개수와 'b' 문자의 개수가 같은 모든 부분 문자열을 반복적으로 제거할 수 있습니다. 각 제거 후에는 문자열의 남은 부분들이 간격 없이 합쳐집니다.

이러한 연산을 몇 번이든 수행한 후 얻을 수 있는 문자열의 최소 길이를 나타내는 정수를 반환하세요.

예시 1:

입력: s = "aabbab"
출력: 0
설명:
부분 문자열 "aabbab"는 'a' 3개와 'b' 3개를 가집니다. 개수가 같으므로 전체 문자열을 직접 제거할 수 있습니다. 최소 길이는 0입니다.

예시 2:

입력: s = "aaaa"
출력: 4
설명:
"aaaa"의 모든 부분 문자열은 'a' 문자만 포함합니다. 결과적으로 제거할 수 있는 부분 문자열이 없으므로 최소 길이는 4로 유지됩니다.

예시 3:

입력: s = "aaabb"
출력: 1
설명:
먼저 부분 문자열 "ab"를 제거하면 "aab"가 남습니다. 다음으로, 새로 생긴 부분 문자열 "ab"를 제거하면 "a"가 남습니다. 더 이상 제거할 수 없으므로 최소 길이는 1입니다.

제약 조건:

1 <= s.length <= 10^5
s[i]는 'a' 또는 'b' 중 하나입니다.
*/
