class Solution
{
public:
    int alternatingSum(const vector<int>& nums) const
    {
        assert(nums.size() >= (MIN_LENGTH) && nums.size() <= (MAX_LENGTH));

        const size_t length = nums.size();
        int sum = 0;

        for (size_t i = 0; i < length; ++i)
        {
            if (i % 2 == 0)
            {
                sum += nums[i];
            }
            else
            {
                sum -= nums[i];
            }
        }

        return sum;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_VAL = 1,
        MAX_VAL = 100
    };
};

// https://leetcode.com/problems/compute-alternating-sum/

/*

## 3701. 교차 합계 계산하기

정수 배열 `nums`가 주어집니다.

`nums`의 교차 합계는 짝수 인덱스의 요소는 더하고 홀수 인덱스의 요소는 뺀 값입니다. 
즉, `nums[0] - nums[1] + nums[2] - nums[3]...` 입니다.

`nums`의 교차 합계를 나타내는 정수를 반환하세요.

**예제 1:**

**입력:** `nums = [1,3,5,7]`
**출력:** -4
**설명:**
짝수 인덱스(0, 2)에 있는 요소는 `nums[0] = 1`과 `nums[2] = 5`입니다.
홀수 인덱스(1, 3)에 있는 요소는 `nums[1] = 3`과 `nums[3] = 7`입니다.
교차 합계는 `nums[0] - nums[1] + nums[2] - nums[3] = 1 - 3 + 5 - 7 = -4`입니다.

**예제 2:**

**입력:** `nums = [100]`
**출력:** 100
**설명:**
짝수 인덱스(0)에 있는 유일한 요소는 `nums[0] = 100`입니다.
홀수 인덱스에는 요소가 없습니다.
교차 합계는 `nums[0] = 100`입니다.

**제약 조건:**

*   `1 <= nums.length <= 100`
*   `1 <= nums[i] <= 100`
*/
