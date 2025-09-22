class Solution
{
public:
    int evenNumberBitwiseORs(vector<int>& nums) const
    {
        assert(nums.size() >= MIN_LENGTH && nums.size() <= MAX_LENGTH);

        int orResult = 0;
        for (const int value : nums)
        {
            assert(value >= MIN_VALUE && value <= MAX_VALUE);
            if ((value & 1) == 0)
            {
                orResult |= value;
            }
        }

        return orResult;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_VALUE  = 1,
        MAX_VALUE  = 100
    };
};

// https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array/

/*

정수 배열 `nums`가 주어집니다.

배열에 있는 모든 짝수의 비트 OR(bitwise OR) 연산 결과를 반환하세요.

만약 `nums`에 짝수가 없다면 0을 반환하세요.

**예시 1:**

**입력:** `nums = [1,2,3,4,5,6]`
**출력:** 6
**설명:**
짝수는 2, 4, 6입니다. 이들의 비트 OR 연산 결과는 6입니다. (2 | 4 | 6 = 6)

**예시 2:**

**입력:** `nums = [7,9,11]`
**출력:** 0
**설명:**
짝수가 없으므로 결과는 0입니다.

**예시 3:**

**입력:** `nums = [1,8,16]`
**출력:** 24
**설명:**
짝수는 8과 16입니다. 이들의 비트 OR 연산 결과는 24입니다. (8 | 16 = 24)

**제약 조건:**

*   `1 <= nums.length <= 100`
*   `1 <= nums[i] <= 100`
*/
