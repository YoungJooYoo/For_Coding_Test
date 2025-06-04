class Solution 
{
public:
    string shortestSuperstring(const string& s1, const string& s2) const
    {
        assert(s1.size() >= MIN_LEN && s1.size() <= MAX_LEN);
        assert(s2.size() >= MIN_LEN && s2.size() <= MAX_LEN);

        if (s1.find(s2) != string::npos) 
        {
            return s1;
        }
        else if (s2.find(s1) != string::npos) 
        {
            return s2;
        }

        const size_t maxOverlap12 = findMaxOverlap(s1, s2);
        const string merged12 = s1 + s2.substr(maxOverlap12);

        const size_t maxOverlap21 = findMaxOverlap(s2, s1);
        const string merged21 = s2 + s1.substr(maxOverlap21);

        if (merged12.size() <= merged21.size()) 
        {
            return merged12;
        }
        else 
        {
            return merged21;
        }
    }

private:
    static size_t findMaxOverlap(const string& strA, const string& strB)
    {
        const size_t lenA   = strA.size();
        const size_t lenB   = strB.size();
        const size_t maxLen = (lenA < lenB ? lenA : lenB);

        for (size_t l = maxLen; l > 0; --l) 
        {
            if (strA.compare(lenA - l, l, strB, 0, l) == 0) 
            {
                return l;
            }
        }

        return 0;
    }

private:
    enum
    {
        MIN_LEN = 1,
        MAX_LEN = 100
    };
};

// https://leetcode.com/problems/find-the-shortest-superstring-ii/description/

/*
**문제 3571. 가장 짧은 슈퍼스트링 II 찾기**
쉬움

---

두 개의 문자열 `s1`과 `s2`가 주어집니다. 두 문자열 모두를 **부분 문자열**로 포함하는 가장 짧은 문자열을 반환하세요. 가능한 해답이 여러 개라면, 그중 아무 것이나 반환하면 됩니다.

> **부분 문자열**(substring)이란, 하나의 문자열 안에서 연속된 문자들의 순서를 의미합니다.

---

## 예시 1

```
입력: s1 = "aba", s2 = "bab"
출력: "abab"
```

**설명:**

* `"abab"`은 `"aba"`와 `"bab"`을 모두 연속된 형태(부분 문자열)로 포함하면서 가장 짧은 문자열입니다.

---

## 예시 2

```
입력: s1 = "aa", s2 = "aaa"
출력: "aaa"
```

**설명:**

* `"aa"`는 이미 `"aaa"`에 포함되어 있으므로, 두 문자열을 모두 포함하는 가장 짧은 문자열은 `"aaa"`입니다.

---

## 제약사항

* `1 ≤ s1.length ≤ 100`
* `1 ≤ s2.length ≤ 100`
* `s1`과 `s2`는 소문자 영어 알파벳으로만 이루어져 있습니다.

*/
