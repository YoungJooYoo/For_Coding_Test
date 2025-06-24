class Solution 
{
public:
    int partitionArray(vector<int>& nums, const int k) const
    {
        assert(MIN_NUMS_LENGTH <= nums.size() && nums.size() <= MAX_NUMS_LENGTH);
        assert(MIN_K <= k && k <= MAX_K);
      
        ranges::sort(nums);
        const size_t numsLength = nums.size();
        int subsequenceCount = 0;
        size_t groupStartIdx = 0;

        while (groupStartIdx < numsLength)
        {
            ++subsequenceCount; 
            const int groupMinValue = nums[groupStartIdx];
            assert(MIN_VALUE <= groupMinValue && groupMinValue <= MAX_VALUE);
            while (groupStartIdx < numsLength && nums[groupStartIdx] - groupMinValue <= k)
            {
                ++groupStartIdx;
            }
        }

        return subsequenceCount;
    }

private:
    enum
    {
        MIN_NUMS_LENGTH = 1,
        MAX_NUMS_LENGTH = 100000,
        MIN_VALUE = 0,
        MAX_VALUE = 100000,
        MIN_K = 0,
        MAX_K = 100000
    };
};

// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/description/?envType=daily-question&envId=2025-06-19

/*
**Difference Is K**
중간 난이도

---

정수 배열 `nums`와 정수 `k`가 주어집니다.

`nums`의 모든 원소를 정확히 한 번씩 포함하는 **하나 이상의 부분수열**로 나누려고 합니다.
각 부분수열에서 **최댓값과 최솟값의 차이가 k 이하**가 되도록 나눌 때,
필요한 부분수열의 **최소 개수**를 반환하세요.

> **부분수열**(subsequence)은, 원래 배열에서 일부 원소를(0개 이상) 삭제해서, 순서를 바꾸지 않고 만들 수 있는 시퀀스를 말합니다.

---

## 예시 1

```
입력: nums = [3,6,1,2,5], k = 2
출력: 2
```

**설명:**

* \[3,1,2], \[6,5]로 나눌 수 있습니다.
* 첫 번째 부분수열의 차이: 3 - 1 = 2
* 두 번째 부분수열의 차이: 6 - 5 = 1
* 총 2개의 부분수열이 필요하며, 이것이 최소입니다.

---

## 예시 2

```
입력: nums = [1,2,3], k = 1
출력: 2
```

**설명:**

* \[1,2], \[3]로 나눌 수 있습니다.
* 다른 최적해: \[1], \[2,3]
* 두 경우 모두 2개의 부분수열로 충분합니다.

---

## 예시 3

```
입력: nums = [2,2,4,5], k = 0
출력: 3
```

**설명:**

* \[2,2], \[4], \[5]로 나눌 수 있습니다.
* 각 부분수열마다 최댓값-최솟값의 차이가 0입니다.

---

## 제약사항

* 1 ≤ nums.length ≤ 10⁵
* 0 ≤ nums\[i] ≤ 10⁵
* 0 ≤ k ≤ 10⁵

---

**힌트:**

* 부분수열에서 중요한 값은 **최대값과 최소값**입니다.
* 한 부분수열의 최대값과 최소값 사이에 속하는 값들은 모두 같은 부분수열에 포함시키는 것이 최적입니다.
* 배열을 정렬하고 그리디하게 묶는 것이 효과적입니다.

*/
