class Solution
{
public:
    int maximizeExpressionOfThree(vector<int>& nums) const
    {
        const size_t LENGTH = nums.size();
        assert(MIN_LENGTH <= LENGTH && LENGTH <= MAX_LENGTH);

        ranges::sort(nums);
        
        const int maxNum = nums[LENGTH - 1];
        const int secondMaxNum = nums[LENGTH - 2];
        const int minNum = nums[0];

        return (maxNum + secondMaxNum - minNum);
    }

private:
    enum
    {
        MIN_LENGTH = 3,
        MAX_LENGTH = 100,
        MIN_VALUE = -100,
        MAX_VALUE = 100
    };
};

// https://leetcode.com/problems/maximize-expression-of-three-elements/description/

/*
### 3745. 세 요소 표현식 최대화

**힌트**
정수 배열 `nums`가 주어집니다.

배열에서 **서로 다른 인덱스**에 있는 세 요소 `a, b, c`를 선택하여 표현식 `a + b - c`의 값이 최대가 되도록 하세요.

이 표현식의 가능한 최대값을 나타내는 정수를 반환하세요.

**예시 1:**

**입력:** `nums = [1,4,2,5]`
**출력:** `8`
**설명:**
`a = 4`, `b = 5`, `c = 1`을 선택할 수 있습니다. 표현식의 값은 `4 + 5 - 1 = 8`이며, 이것이 가능한 최대값입니다.

**예시 2:**

**입력:** `nums = [-2,0,5,-2,4]`
**출력:** `11`
**설명:**
`a = 5`, `b = 4`, `c = -2`를 선택할 수 있습니다. 표현식의 값은 `5 + 4 - (-2) = 11`이며, 이것이 가능한 최대값입니다.

**제약 조건:**

*   `3 <= nums.length <= 100`
*   `-100 <= nums[i] <= 100`
*/
