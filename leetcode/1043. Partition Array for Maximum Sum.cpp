class Solution
{
public:
    int maxSumAfterPartitioning(const vector<int>& arr, const size_t k) const
    {
        assert(arr.size() >= MIN_ARR_LENGTH && arr.size() <= MAX_ARR_LENGTH);
        assert(k >= MIN_ARR_LENGTH && k <= arr.size());

        const size_t n = arr.size();
        vector<int> dp(n + 1, 0);

        for (size_t i = 0; i < n; ++i)
        {
            assert(arr[i] >= MIN_ARR_VALUE && arr[i] <= MAX_ARR_VALUE);
            int maxInPartition = 0;
            for (size_t len = 1; len <= k && i + len <= n; ++len)
            {
                maxInPartition = max(maxInPartition, arr[i + len - 1]);
                dp[i + len] = max(dp[i + len], dp[i] + maxInPartition * static_cast<int>(len));
            }
        }

        return dp[n];
    }

private:
    enum
    {
        MIN_ARR_LENGTH  = 1,
        MAX_ARR_LENGTH  = 500,
        MIN_ARR_VALUE   = 0,
        MAX_ARR_VALUE   = 1000000000
    };
};

// https://leetcode.com/problems/partition-array-for-maximum-sum/description/

/*
**문제 1043. 최대 합을 위한 배열 분할**
중간 난이도

---

주어진 정수 배열 `arr`를 길이가 최대 `k`인 (연속된) 서브배열들로 분할하려고 합니다. 분할된 각 서브배열에 대해서, 그 서브배열의 모든 값은 해당 서브배열에서의 최대값으로 변경됩니다.

분할 이후에 얻을 수 있는 배열의 합의 최댓값을 구하여 반환하세요. 테스트 케이스는 결과가 32비트 정수형에 맞도록 생성됩니다.

---

## 예시 1

```text
입력: arr = [1, 15, 7, 9, 2, 5, 10], k = 3
출력: 84
설명: 배열을 [15,15,15, 9,10,10,10] 으로 변경했을 때 합이 84입니다.
```

## 예시 2

```text
입력: arr = [1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3], k = 4
출력: 83
```

## 예시 3

```text
입력: arr = [1], k = 1
출력: 1
```

---

## 제약사항

* `1 <= arr.length <= 500`
* `0 <= arr[i] <= 10^9`
* `1 <= k <= arr.length`

*/
