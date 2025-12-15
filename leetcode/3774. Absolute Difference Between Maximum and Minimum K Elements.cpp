class Solution 
{
public:
    int absDifference(vector<int>& nums, const int k) const
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);
        assert(MIN_K <= k && k <= nums.size());
        ranges::sort(nums);

        const size_t LENGTH = nums.size();
        int sum = 0;

        for (size_t i = 0; i < k; ++i)
        {
            assert(MIN_NUM <= nums[i] && nums[i] <= MAX_NUM);
            assert(MIN_NUM <= nums[LENGTH - 1 - i] && nums[LENGTH - 1 - i] <= MAX_NUM);
            sum +=(nums[i] - nums[LENGTH - 1 - i]);
        }

        return abs(sum);
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_K = 1,
        MIN_NUM = 1,
        MAX_NUM = 100
    };
};

// https://leetcode.com/problems/absolute-difference-between-maximum-and-minimum-k-elements/

/*
네, 해당 문제를 한국어로 번역해 드리겠습니다.

### 3774. 최대 및 최소 K개 요소 합의 절대 차이

**힌트**
정수 배열 `nums`와 정수 `k`가 주어집니다.

다음 두 값 사이의 절대 차이를 구하세요:

1.  배열에서 **가장 큰 `k`개 요소들의 합**
2.  배열에서 **가장 작은 `k`개 요소들의 합**

이 차이를 나타내는 정수를 반환하세요.

**예시 1:**

**입력:** `nums = [5,2,2,4]`, `k = 2`
**출력:** `5`
**설명:**
*   `k = 2`인 가장 큰 요소들은 4와 5입니다. 그 합은 `4 + 5 = 9`입니다.
*   `k = 2`인 가장 작은 요소들은 2와 2입니다. 그 합은 `2 + 2 = 4`입니다.
*   절대 차이는 `abs(9 - 4) = 5`입니다.

**예시 2:**

**입력:** `nums = [100]`, `k = 1`
**출력:** `0`
**설명:**
*   가장 큰 요소는 100입니다.
*   가장 작은 요소는 100입니다.
*   절대 차이는 `abs(100 - 100) = 0`입니다.

**제약 조건:**

*   `1 <= n == nums.length <= 100`
*   `1 <= nums[i] <= 100`
*   `1 <= k <= n`
*/
