class Solution
{
public:
    int firstStableIndex(const vector<int>& nums, const int k) const
    {
        assert(MIN_LENGTH <= static_cast<int>(nums.size()) && static_cast<int>(nums.size()) <= MAX_LENGTH);
        assert(MIN_K <= k && k <= MAX_K);

        const size_t numsLength = nums.size();

        for (size_t i = 0; i < numsLength; ++i)
        {
            assert(MIN_VALUE <= nums[i] && nums[i] <= MAX_VALUE);
            const int leftMax = *max_element(nums.begin(), nums.begin() + i + 1);
            const int rightMin = *min_element(nums.begin() + i, nums.end());
            const int instabilityScore = leftMax - rightMin;
            if (instabilityScore <= k)
            {
                return static_cast<int>(i);
            }
        }

        return FAIL;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_VALUE  = 0,
        MAX_VALUE  = 1000000000,
        MIN_K      = 0,
        MAX_K      = 1000000000,
        FAIL       = -1,
    };
};

/*

https://leetcode.com/problems/smallest-stable-index-i/description/

**3903. 가장 작은 안정 인덱스 I**

길이가 `n`인 정수 배열 `nums`와 정수 `k`가 주어집니다.

각 인덱스 `i`에 대해 **불안정 점수**를 다음과 같이 정의합니다:

```
불안정 점수 = max(nums[0..i]) - min(nums[i..n-1])
```

- `max(nums[0..i])` → 인덱스 0부터 i까지의 **최댓값**
- `min(nums[i..n-1])` → 인덱스 i부터 n-1까지의 **최솟값**

불안정 점수가 `k` **이하**인 인덱스를 **안정 인덱스**라고 합니다.

**가장 작은 안정 인덱스**를 반환하세요. 없으면 `-1`을 반환하세요.

---

**예시 1**
- 입력: `nums = [5,0,1,4]`, `k = 3`
- 출력: `3`
- 설명:

| 인덱스 | max(0..i) | min(i..n-1) | 불안정 점수 | 안정 여부 |
|--------|-----------|-------------|------------|---------|
| 0 | 5 | 0 | 5 - 0 = 5 | ❌ |
| 1 | 5 | 0 | 5 - 0 = 5 | ❌ |
| 2 | 5 | 1 | 5 - 1 = 4 | ❌ |
| 3 | 5 | 4 | 5 - 4 = 1 | ✅ → 반환 |

**예시 2**
- 입력: `nums = [3,2,1]`, `k = 1`
- 출력: `-1`
- 설명: 모든 인덱스의 불안정 점수가 `2`로 `k=1` 초과 → `-1`

**예시 3**
- 입력: `nums = [0]`, `k = 0`
- 출력: `0`
- 설명: 인덱스 0의 불안정 점수 `0 - 0 = 0` ≤ `k=0` → `0` 반환

---

**제약 조건**
- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 10^9`
- `0 <= k <= 10^9`

---

## 요약

각 인덱스 `i`에서 **왼쪽 최댓값 - 오른쪽 최솟값 ≤ k** 를 만족하는 **첫 번째 인덱스** 반환.

---

## 풀이 방향

**전처리로 O(n) 해결:**

1. `prefixMax[i]` = `nums[0..i]` 의 최댓값 배열 미리 계산
2. `suffixMin[i]` = `nums[i..n-1]` 의 최솟값 배열 미리 계산
3. 각 인덱스 `i` 에서 `prefixMax[i] - suffixMin[i] <= k` 확인
4. 처음 만족하는 `i` 반환, 없으면 `-1`


*/
