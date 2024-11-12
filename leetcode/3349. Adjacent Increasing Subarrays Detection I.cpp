class Solution 
{
public:
    bool hasIncreasingSubarrays(const vector<int>& nums, const int k) 
    {
        const size_t LENGTH = nums.size();

        for (size_t i = 0; i <= LENGTH - (2 * k); ++i)
        {
            if (hasIncreasingSubarraysHelper(i, i + k, nums) == true &&  hasIncreasingSubarraysHelper(i + k, i + 2 * k, nums) == true)
            {
                return true;
            }
        }

        return false;
    }

private:
    bool hasIncreasingSubarraysHelper(const size_t start, const size_t end, const vector<int>& nums)
    {
        bool result = true;

        for (size_t i = start; i < end - 1; ++i)
        {
            if (nums[i] >= nums[i + 1])
            {
                result = false;
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/

/*


**3349. 인접한 증가하는 부분 배열 감지 I**  
난이도: 쉬움

---

정수 `n`개로 이루어진 배열 `nums`와 정수 `k`가 주어질 때, 길이가 `k`인 **두 개의 인접한 부분 배열**이 엄격히 증가하는지 확인하세요. 특히, 인덱스 `a`와 `b` (`a < b`)에서 시작하는 두 부분 배열 `nums[a..a + k - 1]` 및 `nums[b..b + k - 1]`이 다음 조건을 만족하는지 확인해야 합니다:

1. 두 부분 배열 모두 엄격히 증가하는 부분 배열입니다.
2. 두 부분 배열은 인접해야 하며, 이는 `b = a + k`임을 의미합니다.

이러한 두 부분 배열을 찾을 수 있다면 `true`를 반환하고, 그렇지 않으면 `false`를 반환하세요.

---

### 예제 1:

입력: 
```
nums = [2,5,7,8,9,2,3,4,3,1], k = 3
```
출력: 
```
true
```
설명:
- 인덱스 `2`에서 시작하는 부분 배열은 `[7, 8, 9]`로, 엄격히 증가합니다.
- 인덱스 `5`에서 시작하는 부분 배열은 `[2, 3, 4]`로, 엄격히 증가합니다.
- 이 두 부분 배열은 인접하므로 결과는 `true`입니다.

### 예제 2:

입력: 
```
nums = [1,2,3,4,4,4,4,5,6,7], k = 5
```
출력: 
```
false
```
설명:
- 길이가 `k = 5`인 두 인접한 부분 배열이 모두 엄격히 증가하지 않습니다.

---

### 제약 사항:

- `2 <= nums.length <= 100`
- `1 < 2 * k <= nums.length`
- `-1000 <= nums[i] <= 1000`

이 문제는 길이가 `k`인 인접한 두 부분 배열이 엄격히 증가하는지 확인하는 문제입니다. 배열 내의 연속된 구간을 탐색하고 조건을 만족하는지 여부를 판단해야 합니다.
*/
