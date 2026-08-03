class Solution
{
public:
    int countValidPrefixes(const string& s) const
    {
        assert(MIN_LENGTH <= s.length() && s.length() <= MAX_LENGTH);

        size_t zeroCount = 0;
        size_t oneCount = 0;
        int validCount = 0;

        for (const char c : s)
        {
            assert(c == '0' || c == '1');
            if (c == '0')
            {
                ++zeroCount;
            }
            else
            {
                ++oneCount;
            }

            const size_t diff = (zeroCount > oneCount) ? (zeroCount - oneCount) : (oneCount - zeroCount);

            if (diff <= MAX_COUNT_DIFF)
            {
                ++validCount;
            }
        }

        assert(validCount >= 0);
        return validCount;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MAX_COUNT_DIFF = 1
    };
};

/*
https://leetcode.com/problems/count-valid-prefixes/description/
## 4006. 유효한 접두사 개수 세기 (Count Valid Prefixes)

**난이도: Easy**

이진 문자열 `s`가 주어집니다.

`s`의 접두사(prefix)는 그 문자들을 재배열하여 **교대 문자열(alternating string)**을 만들 수 있으면 **유효**하다고 간주합니다.

`s`의 유효한 접두사의 개수를 반환하세요.

인접한 두 문자가 같지 않은 문자열을 **교대 문자열**이라고 합니다.

---

**예제 1:**
```
입력: s = "00101"
출력: 3
설명:
유효한 접두사는 다음과 같습니다:

- "0": 이미 교대 문자열입니다.
- "001": "010"으로 재배열할 수 있으며, 이는 교대 문자열입니다.
- "00101": "01010"으로 재배열할 수 있으며, 이는 교대 문자열입니다.

따라서 정답은 3입니다.
```

**예제 2:**
```
입력: s = "101"
출력: 3
설명:
s = "101"의 모든 접두사가 이미 교대 문자열입니다. 따라서 정답은 3입니다.
```

---

**제약 조건:**
- `1 <= s.length <= 100`
- `s`는 `'0'`과 `'1'`로만 구성됩니다.

---

용어 보충:
- **접두사(prefix)**: 문자열의 맨 앞부터 연속으로 자른 부분. `"00101"`의 접두사는 `"0"`, `"00"`, `"001"`, `"0010"`, `"00101"` 총 5개입니다.
- **교대 문자열**: `"0101"`, `"10"`처럼 같은 문자가 연달아 나오지 않는 문자열.
*/
