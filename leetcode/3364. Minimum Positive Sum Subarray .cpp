class Solution 
{
public:
    int minimumSumSubarray(const vector<int>& nums, const int l, const int r) 
    {
        const size_t LENGTH = nums.size();
        int minSum = numeric_limits<int>::max();

        for (int size = l; size <= r; ++size)
        {
            for (size_t start = 0; start <= LENGTH - size; ++start)
            {
                int sum = 0;
                for (size_t k = start; k < start + size; ++k)
                {
                    sum += nums[k];
                }
                if (sum > 0)
                {
                    minSum = min(minSum, sum);
                }
            }
        }

        return (minSum == numeric_limits<int>::max()) ? -1 : minSum;
    }
};

// https://leetcode.com/problems/minimum-positive-sum-subarray/description/

/*

**3364. 최소 양의 합 부분 배열**  
난이도: 쉬움

---

정수 배열 `nums`와 두 정수 `l`, `r`이 주어집니다. 크기가 `l` 이상 `r` 이하인 부분 배열 중에서 **합이 0보다 큰** 부분 배열의 최소 합을 찾는 것이 목표입니다.

해당하는 부분 배열이 없다면 `-1`을 반환하세요.

부분 배열은 배열 내에서 연속된 비어 있지 않은 요소들의 서열입니다.

---

### 예제 1:

입력:
```
nums = [3, -2, 1, 4], l = 2, r = 3
```
출력:
```
1
```
설명:

길이가 `l = 2`에서 `r = 3` 사이인 합이 0보다 큰 부분 배열은 다음과 같습니다:

- `[3, -2]` 합: 1
- `[1, 4]` 합: 5
- `[3, -2, 1]` 합: 2
- `[-2, 1, 4]` 합: 3

이 중에서 `[3, -2]`의 합이 `1`로 가장 작습니다. 따라서 정답은 `1`입니다.

### 예제 2:

입력:
```
nums = [-2, 2, -3, 1], l = 2, r = 3
```
출력:
```
-1
```
설명:

길이가 `l`에서 `r` 사이인 부분 배열 중 합이 0보다 큰 부분 배열이 없습니다. 따라서 정답은 `-1`입니다.

### 예제 3:

입력:
```
nums = [1, 2, 3, 4], l = 2, r = 4
```
출력:
```
3
```
설명:

부분 배열 `[1, 2]`의 길이가 `2`이고 합이 0보다 큰 최소 합은 `3`입니다. 따라서 정답은 `3`입니다.

---

### 제약 사항:

- `1 <= nums.length <= 100`
- `1 <= l <= r <= nums.length`
- `-1000 <= nums[i] <= 1000`

이 문제는 배열에서 특정 길이 범위 내에 있는 부분 배열의 합이 양수인 최소값을 찾는 문제입니다.
*/
