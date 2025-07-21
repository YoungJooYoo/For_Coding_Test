class Solution
{
public:
    bool checkDivisibility(const int n) const
    {
        assert(MIN_N <= n && n <= MAX_N);

        int sum = 0;
        int product = 1;
        int number = n;

        while (number != 0)
        {
            const int digit = number % 10;
            sum += digit;
            product *= digit;
            number /= 10;
        }

        const int total = sum + product;
        assert(total != 0);

        return (n % total == 0) ? true : false;
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = 1000000
    };
};


/*

## 3622. 자릿수 합과 곱의 합으로 나누어지는지 확인하기

**난이도: 하**

---

### 문제 설명

양의 정수 `n`이 주어집니다.
아래 두 값을 더한 수로 `n`이 나누어지는지 확인하세요.

1. **n의 자릿수 합** (각 자리 숫자의 합)
2. **n의 자릿수 곱** (각 자리 숫자의 곱)

즉,
**(자릿수 합) + (자릿수 곱)** 의 값을 `sum`이라고 할 때
`n % sum == 0`이면 true, 아니면 false를 반환하세요.

---

### 예시

#### 예시 1

**입력:**
n = 99

**출력:**
true

**설명:**
99의 자릿수 합은 9 + 9 = 18,
자릿수 곱은 9 × 9 = 81,
둘의 합은 18 + 81 = 99.
99가 99로 나누어떨어지므로 true.

---

#### 예시 2

**입력:**
n = 23

**출력:**
false

**설명:**
23의 자릿수 합은 2 + 3 = 5,
자릿수 곱은 2 × 3 = 6,
둘의 합은 5 + 6 = 11.
23은 11로 나누어떨어지지 않으므로 false.

---

### 제약사항

* 1 <= n <= 1,000,000

---



*/

// https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/
