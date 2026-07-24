class Solution
{
public:
    string smallestSubsequence(const string& s) const
    {
        assert(MIN_LENGTH <= s.length() && s.length() <= MAX_LENGTH);

        size_t lastIndices[ALPHABET_COUNT] = { 0, };
        bool isInStack[ALPHABET_COUNT] = { false, };
        string result;
        result.reserve(ALPHABET_COUNT);

        for (size_t i = 0; i < s.length(); ++i)
        {
            lastIndices[s[i] - 'a'] = i;
        }

        for (size_t i = 0; i < s.length(); ++i)
        {
            const char c = s[i];
            assert('a' <= c && c <= 'z');
            if (isInStack[c - 'a'] == true)
            {
                continue;
            }
            while (result.empty() == false && result.back() > c && lastIndices[result.back() - 'a'] > i)
            {
                isInStack[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(c);
            isInStack[c - 'a'] = true;
        }

        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 1000,
        ALPHABET_COUNT = 26
    };
};
/*
https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/?envType=daily-question&envId=2026-07-19
## 1081. 서로 다른 문자들로 이루어진 가장 작은 부분 수열 (Smallest Subsequence of Distinct Characters)

**난이도: Medium**

문자열 `s`가 주어지면, `s`에 등장하는 **서로 다른 모든 문자를 정확히 한 번씩** 포함하는 부분 수열(subsequence) 중 **사전순으로 가장 작은** 것을 반환하세요.

---

**예제 1:**
```
입력: s = "bcabc"
출력: "abc"
```

**예제 2:**
```
입력: s = "cbacdcbc"
출력: "acdb"
```

---

**제약 조건:**
- `1 <= s.length <= 1000`
- `s`는 영어 소문자로만 구성됩니다.

**참고**: 이 문제는 316번 문제(Remove Duplicate Letters)와 동일합니다.

---

용어 보충 설명:
- **부분 수열(subsequence)**: 원래 문자열에서 일부 문자를 삭제하되(하나도 삭제하지 않아도 됨), 남은 문자들의 순서는 유지한 것
- **사전순으로 가장 작은**: 사전에 먼저 나오는 순서. 예를 들어 `"abc"` < `"acb"` < `"bac"`

예제 2를 풀어보면 `"cbacdcbc"`의 서로 다른 문자는 `a, b, c, d` 네 개이고, 이 넷을 각각 한 번씩 포함하는 부분 수열들(`"cbad"`, `"badc"`, `"acdb"` 등...) 중 사전순으로 가장 앞서는 것이 `"acdb"`입니다.
*/
