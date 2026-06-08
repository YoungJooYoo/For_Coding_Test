class Solution
{
public:
    int sumOfGoodIntegers(const int n, const int k) const
    {
        assert(MIN_N <= n && n <= MAX_N);
        assert(MIN_K <= k && k <= MAX_K);

        int result = 0;
        const int rangeStart = max(1, n - k);
        const int rangeEnd   = n + k;

        for (int i = rangeStart; i <= rangeEnd; ++i)
        {
            const int absDiff  = abs(n - i);
            const int bitwiseAnd = n & i;
            if (absDiff <= k && bitwiseAnd == 0)
            {
                result += i;
            }
        }

        assert(result >= 0);
        return result;
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = 100,
        MIN_K = 1,
        MAX_K = 100,
    };
};



/*

https://leetcode.com/problems/sum-of-compatible-numbers-in-range-i/description/
**3954. 범위 내 호환 가능한 숫자의 합 I**

두 정수 `n`과 `k`가 주어집니다.

양의 정수 `x`는 아래 두 조건을 **모두** 만족하면 **호환 가능(compatible)** 하다고 합니다:

- `abs(n - x) <= k` (n과 x의 절댓값 차이가 k 이하)
- `(n & x) == 0` (n과 x의 비트 AND 연산 결과가 0)

모든 호환 가능한 정수 `x`의 합을 반환하세요.

> `&` 는 비트 AND 연산자입니다.

---

**예시 1**
- 입력: `n = 2`, `k = 3`
- 출력: `10`
- 설명:
  - `x=1`: `abs(2-1)=1 ≤ 3` ✅, `2 & 1 = 10 & 01 = 0` ✅
  - `x=4`: `abs(2-4)=2 ≤ 3` ✅, `2 & 4 = 010 & 100 = 0` ✅
  - `x=5`: `abs(2-5)=3 ≤ 3` ✅, `2 & 5 = 010 & 101 = 0` ✅
  - 합계: `1 + 4 + 5 = 10`

**예시 2**
- 입력: `n = 5`, `k = 1`
- 출력: `0`
- 설명: 범위 `[4, 6]` 내에 호환 가능한 정수 없음

---

**제약 조건**
- `1 <= n <= 100`
- `1 <= k <= 100`

---

## 요약

`x`가 **n과 절댓값 차이 k 이하**이면서 **비트 AND가 0**인 모든 양의 정수 `x`의 합 반환.

---

## 풀이 방향

탐색 범위: `max(1, n-k) ~ n+k`

1. `x`를 `max(1, n-k)` 부터 `n+k` 까지 순회
2. `abs(n - x) <= k` 확인 (범위 내이므로 자동 만족)
3. `(n & x) == 0` 확인
4. 조건 만족하면 합산


*/
