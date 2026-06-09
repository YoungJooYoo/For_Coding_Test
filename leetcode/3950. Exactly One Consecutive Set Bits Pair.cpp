class Solution
{
public:
    bool consecutiveSetBits(const int n) const
    {
        assert(MIN_N <= n && n <= MAX_N);

        const string strBinary = bitset<BINARY_LENGTH>(n).to_string();
        const size_t binaryLength = strBinary.size();
        int consecutivePairCount = 0;

        for (size_t i = 0; i < binaryLength - 1; ++i)
        {
            if (strBinary[i] == '1' && strBinary[i + 1] == '1')
            {
                ++consecutivePairCount;
            }
        }

        return (consecutivePairCount == EXACTLY_ONE_PAIR) ? true : false;
    }

private:
    enum
    {
        MIN_N              = 0,
        MAX_N              = 100000,
        BINARY_LENGTH      = 17,     // 10^5 < 2^17
        EXACTLY_ONE_PAIR   = 1,
    };
};

/*

// https://leetcode.com/problems/exactly-one-consecutive-set-bits-pair/description/

**3950. 정확히 하나의 연속된 비트 쌍**

정수 `n`이 주어집니다.

`n`의 이진 표현에서 **연속된 1 비트 쌍이 정확히 하나**이면 `true`, 아니면 `false`를 반환하세요.

---

**예시 1**
- 입력: `n = 6`
- 출력: `true`
- 설명:
  - 6의 이진수 = `110`
  - 연속된 1 쌍: `"11"` → 정확히 1쌍 ✅

**예시 2**
- 입력: `n = 5`
- 출력: `false`
- 설명:
  - 5의 이진수 = `101`
  - 연속된 1 쌍 없음 ❌

---

**제약 조건**
- `0 <= n <= 10^5`

---

## 요약

이진수에서 `11` (연속된 1) 이 **정확히 1번** 등장하는지 확인.

---

## 풀이 방향

```
n     과 n>>1 을 AND 연산
→ 연속된 1 비트 위치만 추출됨

예시) n = 6 = 110
      n>>1   = 011
      n & (n>>1) = 010  → 1비트가 1개 → true

예시) n = 14 = 1110
      n>>1    = 0111
      n & (n>>1) = 0110 → 1비트가 2개 → false
```

1. `consecutive = n & (n >> 1)` 계산
2. `consecutive`의 **1비트가 정확히 1개**인지 확인
3. `__builtin_popcount(consecutive) == 1` 이면 `true`


*/
