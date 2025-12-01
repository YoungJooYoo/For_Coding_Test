class Solution
{
public:
    vector<int> lexSmallestNegatedPerm(const int n, const long long target) const
    {
        assert(MIN_N <= n && n <= MAX_N);
        assert(MIN_TARGET <= target && target <= MAX_TARGET);

        const long long sumPos = static_cast<long long>(n) * (n + 1) / 2;
        const long long diff = sumPos - target;
        if (diff < 0 || diff % 2 != 0)
        {
            return {};
        }

        long long remain = diff / 2;
        vector<bool> neg(n + 1, false);
        for (int x = n; x >= 1; --x)
        {
            if (remain >= x)
            {
                remain -= x;
                neg[x] = true;
            }
        }

        if (remain != 0)
        {
            return {};
        }

        vector<int> result(n);
        for (int i = 0; i < n; ++i)
        {
            const int x = i + 1;
            result[i] = neg[x] ? -x : x;
        }

        sort(result.begin(), result.end());
        return result;
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = 100000,
        MIN_TARGET = -10000000000LL,
        MAX_TARGET = 10000000000LL
    };
};

// https://leetcode.com/problems/lexicographically-smallest-negated-permutation-that-sums-to-target/

/*
### 3752. 타겟 합을 만족하는 사전순으로 가장 작은 부호가 있는 순열

**힌트**  
양의 정수 `n`과 정수 `target`이 주어집니다.

크기가 `n`인 정수 배열을 반환하세요. 이 배열은 다음 조건을 모두 만족해야 합니다:

1. 배열의 모든 요소의 합이 `target`과 같아야 합니다.
2. 배열의 각 요소의 절대값은 크기가 `n`인 순열을 이룹니다. (즉, 절대값이 `1, 2, ..., n`의 순열이어야 합니다.)

만약 그러한 배열이 존재하지 않으면 빈 배열을 반환하세요.

**크기 `n`의 순열**은 정수 `1, 2, ..., n`을 재배열한 것입니다.

**예시 1:**

**입력:** `n = 3`, `target = 0`  
**출력:** `[-3, 1, 2]`  
**설명:**  
합이 `0`이고 절대값이 `1, 2, 3`의 순열인 배열은 다음과 같습니다:  
`[-3, 1, 2]`, `[-3, 2, 1]`, `[-2, -1, 3]`, ...  
이 중 사전순으로 가장 작은 배열은 `[-3, 1, 2]`입니다.

**예시 2:**

**입력:** `n = 1`, `target = 10000000000`  
**출력:** `[]`  
**설명:**  
크기가 `1`인 순열의 절대값은 `1`이어야 하므로, 합이 `10000000000`인 배열은 존재하지 않습니다.

**제약 조건:**

*   `1 <= n <= 10^5`
*   `-10^10 <= target <= 10^10`

*/
