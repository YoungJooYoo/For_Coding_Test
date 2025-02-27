class Solution 
{
public:
    int lenLongestFibSubseq(const vector<int>& arr) const
    {
        const size_t n = arr.size();
        unordered_map<int, int> indexMap;
        vector<vector<int>> dp(n, vector<int>(n, 2));// dp[i][j]: arr[i]와 arr[j]를 마지막 두 항으로 하는 피보나치 유사 수열의 길이
        int maxLength = 0;

        assert(n >= MIN_ARR_SIZE && n <= MAX_ARR_SIZE);
        for (size_t i = 0; i < n; i++)
        {
            assert(arr[i] >= MIN_NUM && arr[i] <= MAX_NUM);
            indexMap[arr[i]] = i;
        }
        
        for (size_t j = 0; j < n; j++) // 모든 가능한 쌍 (i, j)를 탐색 (i < j)
        {
            for (size_t i = 0; i < j; i++)
            {
                const int target = arr[j] - arr[i];
                if (indexMap.find(target) != indexMap.end()) // target 값이 존재하고, 그 인덱스가 i보다 작다면
                {
                    const int k = indexMap.at(target);
                    if (k < static_cast<int>(i))
                    {
                        dp[i][j] = dp[k][i] + 1;
                        maxLength = max(maxLength, dp[i][j]);
                    }
                }
            }
        }
        
        return (maxLength >= 3) ? maxLength : 0;
    }

private:
    enum
    {
        MIN_ARR_SIZE = 3,
        MAX_ARR_SIZE = 1000,
        MIN_NUM = 1,
        MAX_NUM = 1000000000,
    };
};

// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/?envType=daily-question&envId=2025-02-27

/*

**문제: 가장 긴 피보나치 유사 부분 수열의 길이 찾기**

수열 \(x_1, x_2, \dots, x_n\)이 피보나치 유사하다는 것은 다음 조건을 만족함을 의미합니다:

- \(n \ge 3\)
- 모든 \(i\)에 대해 (단, \(i+2 \le n\)) \(x_i + x_{i+1} = x_{i+2}\)

양의 정수로 구성되어 있고 엄격하게 증가하는 배열 **arr**가 주어집니다. 이 배열로부터 피보나치 유사인 부분 수열 중 가장 긴 것의 길이를 반환하세요. 만약 피보나치 유사 부분 수열이 존재하지 않으면 0을 반환합니다.

**부분 수열(subsequence)** 은 배열 **arr**에서 임의의 개수의 원소(0개 포함)를 삭제하여 남은 원소들의 순서를 유지하면서 구성한 수열입니다. 예를 들어, \([3, 5, 8]\)은 \([3, 4, 5, 6, 7, 8]\)의 부분 수열입니다.

---

**예제 1:**

- **입력:** arr = [1, 2, 3, 4, 5, 6, 7, 8]
- **출력:** 5
- **설명:** 가장 긴 피보나치 유사 부분 수열은 \([1, 2, 3, 5, 8]\)입니다.

---

**예제 2:**

- **입력:** arr = [1, 3, 7, 11, 12, 14, 18]
- **출력:** 3
- **설명:** 가능한 피보나치 유사 부분 수열로는 \([1, 11, 12]\), \([3, 11, 14]\), \([7, 11, 18]\) 등이 있으며, 이들 중 길이가 가장 긴 것은 3입니다.

---

**제약 조건:**

- \(3 \le \text{arr.length} \le 1000\)
- \(1 \le arr[i] < arr[i+1] \le 10^9\) for all valid i


*/
