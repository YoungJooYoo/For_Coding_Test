class Solution
{
public:
    long long minCuttingCost(const int n, const int m, const int k)
    {
        assert(k >= MIN_K && k <= MAX_K);
        assert(n >= MIN_LOG_LENGTH && n <= 2LL * k);
        assert(m >= MIN_LOG_LENGTH && m <= 2LL * k);

        if (n <= k && m <= k)
        {
            return 0LL;
        }
        else if (n > k)
        {
            const long long cutLength = n - k;
            const long long cutCost = cutLength * k;
            return cutCost;
        }

        //  m > k 인 경우
        const long long cutLength = m - k;
        const long long cutCost = cutLength * k;
        return cutCost;
    }

private:
    enum
    {
        MIN_LOG_LENGTH = 1,     // 1 ≤ n, m
        MIN_K          = 2,     // 2 ≤ k
        MAX_K          = 100000 // k ≤ 10^5
    };
};

// https://leetcode.com/problems/find-minimum-log-transportation-cost/description/

/*
**문제 3560. 최소 통나무 운송 비용**
쉬움

---

정수 `n`, `m`, `k`가 주어집니다.

길이가 `n`과 `m`인 두 통나무를 세 대의 트럭에 실어야 합니다. 각 트럭은 길이가 최대 `k`인 통나무 하나만 실을 수 있습니다.

필요하다면 통나무를 잘라서 더 작은 조각으로 만들 수 있으며, 길이 `x`인 통나무를 길이 `len1`과 `len2`인 두 조각으로 자를 때 발생하는 비용은

```
cost = len1 * len2
```

단, `len1 + len2 = x` 입니다.

모든 통나무 조각을 트럭들에 실을 수 있도록 분배할 때 드는 **총 비용의 최솟값**을 반환하세요.
만약 자르지 않아도 된다면, 총 비용은 0입니다.

---

## 예시 1

```
입력: n = 6, m = 5, k = 5
출력: 5
```

**설명:**

* 길이 6인 통나무를 길이 1과 5로 자르면 비용은 `1 * 5 = 5`입니다.
* 이렇게 하면 길이 1, 5, 5인 세 조각이 각각 트럭에 실릴 수 있습니다.

---

## 예시 2

```
입력: n = 4, m = 4, k = 6
출력: 0
```

**설명:**

* 두 통나무의 길이(4, 4)가 모두 `k=6` 이하이므로 자를 필요가 없고, 비용은 0입니다.

---

## 제약사항

* `2 ≤ k ≤ 10^5`
* `1 ≤ n, m ≤ 2 * k`
* 항상 통나무를 트럭에 실을 수 있도록 입력이 주어집니다.

---

## 힌트

1. 두 통나무 길이가 모두 `k` 이하라면 비용은 0입니다.
2. 만약 두 통나무 길이가 모두 `k`보다 크다면 어떻게 운송할 수 있을까요?
3. 그렇지 않다면, 더 긴 통나무를 `len1`과 `len2`로 잘라 보세요 (`len1 + len2 = 원래 길이`).
4. 비용 `len1 * len2`를 최소화하려면 `len1`과 `len2`를 최대한 멀리 떨어진 값으로 택합니다 (예: `1`과 `length - 1`).


*/
