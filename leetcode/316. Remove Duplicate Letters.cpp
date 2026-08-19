class Solution
{
public:
    string removeDuplicateLetters(const string s)
    {
        assert(MIN_LENGTH <= s.length() && s.length() <= MAX_LENGTH);

        size_t lastIndices[ALPHABET_COUNT] = { 0, };

        for (size_t i = 0; i < s.length(); ++i)
        {
            lastIndices[s[i] - 'a'] = i;
        }

        unordered_set<char> inStack;
        string result;
        result.reserve(ALPHABET_COUNT);

        for (size_t i = 0; i < s.length(); ++i)
        {
            const char c = s[i];
            assert('a' <= c && c <= 'z');
            if (inStack.find(c) != inStack.end())
            {
                continue;
            }

            while (result.empty() == false && result.back() > c && lastIndices[result.back() - 'a'] > i)
            {
                inStack.erase(result.back());
                result.pop_back();
            }

            result.push_back(c);
            inStack.insert(c);
        }

        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 10000,
        ALPHABET_COUNT = 26
    };
};

/*
https://leetcode.com/problems/remove-duplicate-letters/description/

## 316. 중복 문자 제거 (Remove Duplicate Letters)

**난이도: Medium**

문자열 `s`가 주어지면, 모든 문자가 **정확히 한 번씩만** 나타나도록 중복 문자를 제거하세요. 가능한 모든 결과 중 **사전순으로 가장 작은** 결과를 만들어야 합니다.

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
- `1 <= s.length <= 10⁴`
- `s`는 영어 소문자로만 구성됩니다.

**참고**: 이 문제는 1081번 문제(Smallest Subsequence of Distinct Characters)와 동일합니다.

---

참고로 이 문제, **얼마 전에 푸신 1081번과 완전히 동일한 문제**입니다 (LeetCode 공식 노트에도 명시되어 있어요). "중복 제거"라는 표현으로 바뀌었지만, 남은 문자들의 순서가 원본을 따라야 하므로 결국 "서로 다른 모든 문자를 한 번씩 포함하는 사전순 최소 부분 수열"과 같은 문제입니다.

그때 작성한 그리디 + 스택 풀이(마지막 등장 인덱스 + `isInStack` + pop 조건)가 그대로 통과합니다. 유일한 차이는 제약이 `100 → 10⁴`로 커졌다는 것인데, O(n) 풀이라 전혀 문제없고 enum의 `MAX_LENGTH`만 `10000`으로 바꾸면 됩니다.
*/
