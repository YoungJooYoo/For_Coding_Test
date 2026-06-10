class Solution
{
public:
    long long maxTotalValue(const vector<int>& nums, const int k) const
    {
        assert(MIN_LENGTH <= static_cast<int>(nums.size()) && static_cast<int>(nums.size()) <= MAX_LENGTH);
        assert(MIN_K <= k && k <= MAX_K);

        const int globalMax = *max_element(nums.begin(), nums.end());
        const int globalMin = *min_element(nums.begin(), nums.end());
        const long long maxSubarrayValue = static_cast<long long>(globalMax - globalMin);
        const long long result = maxSubarrayValue * static_cast<long long>(k);

        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 50000,
        MIN_VALUE  = 0,
        MAX_VALUE  = 1000000000,
        MIN_K      = 1,
        MAX_K      = 100000,
    };
};

/*

**3689. 최대 서브배열 총 값 I**

길이 `n`인 정수 배열 `nums`와 정수 `k`가 주어집니다.

`nums`에서 정확히 `k`개의 **비어있지 않은 서브배열** `nums[l..r]`을 선택해야 합니다. 서브배열은 **겹쳐도 되고**, **완전히 동일한 서브배열을 여러 번 선택**해도 됩니다.

서브배열 `nums[l..r]`의 **값**은 다음과 같이 정의됩니다:
```
값 = max(nums[l..r]) - min(nums[l..r])
```

**총 값**은 선택한 모든 서브배열의 값의 합입니다.

달성 가능한 **최대 총 값**을 반환하세요.

---

**예시 1**
- 입력: `nums = [1,3,2]`, `k = 2`
- 출력: `4`
- 설명:
  - `nums[0..1] = [1,3]` → `3 - 1 = 2`
  - `nums[0..2] = [1,3,2]` → `3 - 1 = 2`
  - 합계: `2 + 2 = 4`

**예시 2**
- 입력: `nums = [4,2,5,1]`, `k = 3`
- 출력: `12`
- 설명:
  - `nums[0..3]` 두 번 → `4 + 4 = 8`
  - `nums[2..3] = [5,1]` → `5 - 1 = 4`
  - 합계: `4 + 4 + 4 = 12`

---

**제약 조건**
- `1 <= n == nums.length <= 5 * 10^4`
- `0 <= nums[i] <= 10^9`
- `1 <= k <= 10^5`

---

## 요약

**가장 값이 큰 서브배열을 `k`번 반복 선택**하면 최대 총 값이 됨.

---

## 풀이 방향

**핵심 관찰:**
```
어떤 서브배열이든 같은 걸 여러 번 선택 가능
→ 가장 값이 큰 서브배열을 k번 선택하면 최대!
→ 최대값 서브배열 = 전체 배열의 max - min
→ 정답 = (globalMax - globalMin) * k
```

1. `nums`의 전체 최댓값 `globalMax` 계산
2. `nums`의 전체 최솟값 `globalMin` 계산
3. `(globalMax - globalMin) * k` 반환

https://leetcode.com/problems/maximum-total-subarray-value-i/description/?envType=daily-question&envId=2026-06-09

*/
