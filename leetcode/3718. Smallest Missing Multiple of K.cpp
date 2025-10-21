class Solution 
{
public:
    int missingMultiple(vector<int>& nums, const int k) const
    {
        assert(MIN <= nums.size() && nums.size() <= MAX);
        assert(MIN <= k && k <= MAX);

        ranges::sort(nums);

        int num = 0;

        for (size_t i = 1; i <= MAX; ++i)
        {
            num = i * k;
            if (find(nums.begin(), nums.end(), num) == nums.end())
            {
                return num;
            }
        }

        return num + k;
    }

private:
    enum
    {
        MIN = 1,
        MAX = 100
    };
};

// https://leetcode.com/problems/smallest-missing-multiple-of-k/description/

/*

### 3718. K의 최소 누락 배수

**힌트**
정수 배열 `nums`와 정수 `k`가 주어집니다. `nums`에 없는 `k`의 가장 작은 양의 배수를 반환하세요.

`k`의 배수는 `k`로 나누어떨어지는 모든 양의 정수를 의미합니다.

**예시 1:**

**입력:** `nums = [8,2,3,4,6]`, `k = 2`
**출력:** `10`
**설명:**
`k = 2`의 배수는 2, 4, 6, 8, 10, 12... 이며, `nums`에 없는 가장 작은 배수는 10입니다.

**예시 2:**

**입력:** `nums = [1,4,7,10,15]`, `k = 5`
**출력:** `5`
**설명:**
`k = 5`의 배수는 5, 10, 15, 20... 이며, `nums`에 없는 가장 작은 배수는 5입니다.

**제약 조건:**

*   `1 <= nums.length <= 100`
*   `1 <= nums[i] <= 100`
*   `1 <= k <= 100`
*/
