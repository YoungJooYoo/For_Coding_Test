class Solution 
{
public:
    vector<int> findMissingElements(vector<int>& nums) const
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);
        ranges::sort(nums);

        vector<int> numbers(MAX_LENGTH + 1, 0);
        vector<int> result;

        for (const auto num : nums)
        {
            assert(MIN_NUM <= num && num <= MAX_NUM);
            ++numbers[num];
        }

        for (int i = nums[0]; i <= nums[nums.size() - 1]; ++i)
        {
            if (numbers[i] == 0)
            {
                result.push_back(i);
            }
        }

        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 2,
        MAX_LENGTH = 100,
        MIN_NUM = 1,
        MAX_NUM = 100
    };
};

// https://leetcode.com/problems/find-missing-elements/description/

/*

### 1. 누락된 요소 찾기

**힌트**
고유한 정수로 구성된 정수 배열 `nums`가 주어집니다.

원래 `nums`는 특정 범위 내의 모든 정수를 포함하고 있었습니다. 하지만 일부 정수가 배열에서 누락되었을 수 있습니다.

원래 범위의 가장 작은 정수와 가장 큰 정수는 여전히 `nums`에 존재합니다.

이 범위 내에서 누락된 모든 정수를 **정렬된 목록**으로 반환하세요. 만약 누락된 정수가 없다면 빈 목록을 반환합니다.

**예시 1:**

**입력:** `nums = [1,4,2,5]`
**출력:** `[3]`
**설명:**
가장 작은 정수는 1이고 가장 큰 정수는 5입니다. 따라서 전체 범위는 `[1,2,3,4,5]`여야 합니다. 이 중에서 3만 누락되었습니다.

**예시 2:**

**입력:** `nums = [7,8,6,9]`
**출력:** `[]`
**설명:**
가장 작은 정수는 6이고 가장 큰 정수는 9입니다. 따라서 전체 범위는 `[6,7,8,9]`입니다. 모든 정수가 이미 존재하므로 누락된 정수는 없습니다.

**예시 3:**

**입력:** `nums = [5,1]`
**출력:** `[2,3,4]`
**설명:**
가장 작은 정수는 1이고 가장 큰 정수는 5입니다. 따라서 전체 범위는 `[1,2,3,4,5]`여야 합니다. 누락된 정수는 2, 3, 4입니다.

**제약 조건:**

*   `2 <= nums.length <= 100`
*   `1 <= nums[i] <= 100`
*/
