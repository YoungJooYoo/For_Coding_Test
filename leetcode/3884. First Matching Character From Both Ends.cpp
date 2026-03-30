class Solution
{
public:
    int firstMatchingIndex(const string& s) const
    {
        assert(MIN_LENGTH <= static_cast<int>(s.size()) && static_cast<int>(s.size()) <= MAX_LENGTH);

        const int strLength = static_cast<int>(s.size());
        int leftIndex  = 0;
        int rightIndex = strLength - 1;

        while (leftIndex <= rightIndex)
        {
            if (s[leftIndex] == s[rightIndex])
            {
                assert('a' <= s[leftIndex] && s[leftIndex] <= 'z');
                assert('a' <= s[rightIndex] && s[rightIndex] <= 'z');
                return leftIndex;
            }
            ++leftIndex;
            --rightIndex;
        }

        return FAIL;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        FAIL       = -1,
    };
};

/*

## 문제 번역

**3884. 양쪽 끝에서 첫 번째로 일치하는 문자**

소문자 영어 알파벳으로 이루어진 길이 `n`의 문자열 `s`가 주어집니다.

`s[i] == s[n - i - 1]` 을 만족하는 **가장 작은 인덱스** `i`를 반환하세요.
그런 인덱스가 없으면 `-1`을 반환하세요.

---

**예시 1**
- 입력: `s = "abcacbd"`
- 출력: `1`
- 설명:
  - `i = 1` 일 때, `s[1] = 'b'`, `s[5] = 'b'` → 일치 ✅
  - 더 작은 인덱스는 조건을 만족하지 않으므로 답은 `1`

**예시 2**
- 입력: `s = "abc"`
- 출력: `1`
- 설명:
  - `i = 1` 일 때, `s[1] = 'b'`, `s[n - 1 - 1] = s[1] = 'b'` → 같은 위치가 겹쳐서 일치 ✅
  - 더 작은 인덱스는 조건을 만족하지 않으므로 답은 `1`

**예시 3**
- 입력: `s = "abcdab"`
- 출력: `-1`
- 설명:
  - 모든 인덱스 `i`에 대해 `s[i] != s[n - i - 1]` → `-1`

---

**제약 조건**
- `1 <= n == s.length <= 100`
- `s`는 소문자 영어 알파벳으로만 구성

---

## 요약

문자열의 **앞에서 i번째**와 **뒤에서 i번째** 문자가 같은 경우 중 **가장 작은 i**를 반환. 없으면 `-1`.

---

## 풀이 방향

1. `i = 0` 부터 `n/2` 까지 순회
2. `s[i] == s[n - i - 1]` 조건 확인
3. 처음 만족하는 `i` 즉시 반환
4. 끝까지 없으면 `-1` 반환

https://leetcode.com/problems/first-matching-character-from-both-ends/description/
*/
