class Solution
{
public:
    bool isAdjacentDiffAtMostTwo(const string& s) const
    {
        assert(MIN_LENGTH <= static_cast<int>(s.size()) && static_cast<int>(s.size()) <= MAX_LENGTH);

        const size_t strLength = s.size();
        for (size_t i = 0; i < strLength - 1; ++i)
        {
            assert(isdigit(s[i]));
            assert(isdigit(s[i + 1]));
            const int currentDigit = s[i] - '0';
            const int nextDigit = s[i + 1] - '0';
            const int absDiff = abs(currentDigit - nextDigit);

            if (absDiff > MAX_DIFF)
            {
                return false;
            }

        }

        return true;
    }

private:
    enum
    {
        MIN_LENGTH = 2,
        MAX_LENGTH = 100,
        MAX_DIFF   = 2,
    };
};
/*

## 문제 번역

**3931. 인접한 자릿수 차이 확인**

숫자로만 이루어진 문자열 `s`가 주어집니다.

**인접한 모든 자릿수 쌍**의 절댓값 차이가 **2 이하**이면 `true`, 아니면 `false`를 반환하세요.

`a`와 `b`의 절댓값 차이는 `abs(a - b)`로 정의합니다.

---

**예시 1**
- 입력: `s = "132"`
- 출력: `true`
- 설명:
  - `abs(1 - 3) = 2` ≤ 2 ✅
  - `abs(3 - 2) = 1` ≤ 2 ✅

**예시 2**
- 입력: `s = "129"`
- 출력: `false`
- 설명:
  - `abs(1 - 2) = 1` ≤ 2 ✅
  - `abs(2 - 9) = 7` > 2 ❌

---

**제약 조건**
- `2 <= s.length <= 100`
- `s`는 숫자로만 구성

---

## 요약

문자열을 앞에서부터 순회하며 **인접한 두 문자의 숫자 차이가 2 초과**인 경우가 있으면 `false`, 없으면 `true`.

---

## 풀이 방향

1. `i = 0` 부터 `n-2` 까지 순회
2. `abs(s[i] - s[i+1]) > MAX_DIFF(2)` 이면 즉시 `false`
3. 끝까지 통과하면 `true`


*/
