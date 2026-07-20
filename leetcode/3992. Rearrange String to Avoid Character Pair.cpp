class Solution
{
public:
    string rearrangeString(string s, const char x, const char y)
    {
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);
        assert(x != y);
        assert('a' <= x && x <= 'z');
        assert('a' <= y && y <= 'z');

        size_t i = 0;
        size_t j = s.size() - 1;

        while (i < j)
        {
            assert('a' <= s[i] && s[i] <= 'z');
            assert('a' <= s[j] && s[j] <= 'z');
            while (i < j && s[i] != x)
            {
                ++i;
            }
            while (i < j && s[j] != y)
            {
                --j;
            }
            if (i < j)
            {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }

        return s;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100
    };
};

/*
https://leetcode.com/problems/rearrange-string-to-avoid-character-pair/description/

## 3992. 문자 쌍을 피하도록 문자열 재배열하기 (Rearrange String to Avoid Character Pair)

**난이도: Easy**

문자열 `s`와 서로 다른 두 개의 영어 소문자 `x`, `y`가 주어집니다.

`s`의 문자들을 재배열하여 다음 조건을 만족하는 새 문자열 `t`를 만드세요:

- `t`는 `s`의 순열(permutation)이어야 합니다.
- `t`에서 모든 `y`는 모든 `x`보다 앞에 나타나야 합니다.

조건을 만족하는 **아무** 문자열 `t`나 반환하세요.

---

**예제 1:**
```
입력: s = "aabc", x = "a", y = "c"
출력: "cbaa"
설명:
"cbaa"는 "aabc"의 순열이며, 모든 'c'가 모든 'a'보다 앞에 나타납니다.
```

**예제 2:**
```
입력: s = "dcab", x = "d", y = "b"
출력: "cabd"
설명:
"cabd"는 "dcab"의 순열이며, 모든 'b'가 모든 'd'보다 앞에 나타납니다.
```

**예제 3:**
```
입력: s = "axe", x = "o", y = "x"
출력: "axe"
설명:
"axe"는 이미 유효한 문자열입니다. 'o'가 문자열에 존재하지 않으므로,
조건은 자동으로 만족됩니다.
```

---

**제약 조건:**
- `1 <= s.length <= 100`
- `s`는 영어 소문자로만 구성됩니다.
- `x`와 `y`는 영어 소문자입니다.
- `x != y`
*/
