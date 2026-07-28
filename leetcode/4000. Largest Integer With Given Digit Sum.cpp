class Solution
{
public:
    int largestInteger(const int n, const int s) const
    {
        assert(MIN_N <= n && n <= MAX_N);
        assert(MIN_S <= s && s <= MAX_S);

        const int maxSum = MAX_DIGIT * n;

        if (s == 0)
        {
            return 0;
        }
        else if (s > maxSum)
        {
            return FAIL;
        }

        int result = 0;
        int remainingSum = s;

        for (int i = 0; i < n; ++i)
        {
            const int digit = min(static_cast<int>(MAX_DIGIT), remainingSum);
            result = result * BASE + digit;
            remainingSum -= digit;
        }

        assert(remainingSum == 0);
        return result;
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = 5,
        MIN_S = 0,
        MAX_S = 100,
        MAX_DIGIT = 9,
        BASE = 10,
        FAIL = -1
    };
};

/*
https://leetcode.com/problems/largest-integer-with-given-digit-sum/description/
## 4000. 주어진 자릿수 합을 가진 가장 큰 정수 (Largest Integer With Given Digit Sum)

**난이도: Easy**

두 개의 음이 아닌 정수 `n`과 `s`가 주어집니다.

**최대 `n`자리**이면서 **자릿수의 합이 `s`**인 가장 큰 정수를 반환하세요. 그러한 정수가 존재하지 않으면 `-1`을 반환하세요.

---

**예제 1:**
```
입력: n = 2, s = 9
출력: 90
설명:
최대 2자리이면서 자릿수의 합이 9인 가장 큰 정수는 90입니다.
```

**예제 2:**
```
입력: n = 2, s = 19
출력: -1
설명:
최대 2자리이면서 자릿수의 합이 19인 정수는 존재하지 않으므로,
정답은 -1입니다.
```

**예제 3:**
```
입력: n = 5, s = 0
출력: 0
설명:
자릿수의 합이 0인 음이 아닌 정수는 0뿐입니다.
```

---

**제약 조건:**
- `1 <= n <= 5`
- `0 <= s <= 100`
*/
