class Solution
{
public:
    bool checkGoodInteger(const int n) const
    {
        assert(MIN_N <= n && n <= MAX_N);

        const string strNum = to_string(n);
        long long digitSum  = 0;
        long long squareSum = 0;

        for (const char ch : strNum)
        {
            const long long digit = ch - '0';
            digitSum  += digit;
            squareSum += digit * digit;
        }

        return ((squareSum - digitSum) >= GOOD_THRESHOLD) ? true : false;
    }

private:
    enum
    {
        MIN_N          = 1,
        MAX_N          = 1000000000,
        GOOD_THRESHOLD = 50,
    };
};

/*
https://leetcode.com/problems/check-good-integer/description/

**3959. 좋은 정수 확인**

양의 정수 `n`이 주어집니다.

- `digitSum` = `n`의 **각 자릿수의 합**
- `squareSum` = `n`의 **각 자릿수의 제곱의 합**

`squareSum - digitSum >= 50` 이면 **좋은 정수(good integer)** 라고 합니다.

`n`이 좋은 정수이면 `true`, 아니면 `false`를 반환하세요.

---

**예시 1**
- 입력: `n = 1000`
- 출력: `false`
- 설명:
  - 자릿수: `1, 0, 0, 0`
  - `digitSum = 1+0+0+0 = 1`
  - `squareSum = 1²+0²+0²+0² = 1`
  - `squareSum - digitSum = 1 - 1 = 0` → `0 < 50` → `false`

**예시 2**
- 입력: `n = 19`
- 출력: `true`
- 설명:
  - 자릿수: `1, 9`
  - `digitSum = 1+9 = 10`
  - `squareSum = 1²+9² = 1+81 = 82`
  - `squareSum - digitSum = 82 - 10 = 72` → `72 >= 50` → `true`

---

**제약 조건**
- `1 <= n <= 10^9`

---

## 요약

각 자릿수에 대해 **제곱합 - 합 >= 50** 이면 `true`.

---

## 풀이 방향

1. `n`을 문자열로 변환
2. 각 자릿수를 순회하며 `digitSum`, `squareSum` 누적
3. `squareSum - digitSum >= THRESHOLD(50)` 이면 `true`


*/
