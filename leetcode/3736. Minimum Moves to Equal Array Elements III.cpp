class Solution 
{
public:
    int minMoves(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);

        const int maxNum = *max_element(nums.begin(), nums.end());
        int result = 0;

        for (const auto& num : nums)
        {
            assert(MIN_NUM <= num && num <= MAX_NUM);
            result += abs(maxNum - num);
        }

        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_NUM = 1,
        MAX_NUM = 100
    };
};

// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/

/*

### 3736. 배열 요소를 같게 만들기 위한 최소 이동 횟수 III

**힌트**
정수 배열 `nums`가 주어집니다.

한 번의 이동으로, `nums[i]`의 **어떤 단일 요소의 값**을 1 증가시킬 수 있습니다.

`nums`의 모든 요소가 같아지도록 하는 데 필요한 최소 총 이동 횟수를 반환하세요.

**예시 1:**

**입력:** `nums = [2,1,3]`
**출력:** `3`
**설명:**
모든 요소를 같게 만들려면:
*   `nums[0] = 2`를 1 증가시켜 3으로 만듭니다.
*   `nums[1] = 1`을 1 증가시켜 2로 만듭니다.
*   `nums[1] = 2`를 1 증가시켜 3으로 만듭니다.
이제 `nums`의 모든 요소는 3이 되었습니다. 최소 총 이동 횟수는 3입니다.

**예시 2:**

**입력:** `nums = [4,4,5]`
**출력:** `2`
**설명:**
모든 요소를 같게 만들려면:
*   `nums[0] = 4`를 1 증가시켜 5로 만듭니다.
*   `nums[1] = 4`를 1 증가시켜 5로 만듭니다.
이제 `nums`의 모든 요소는 5가 되었습니다. 최소 총 이동 횟수는 2입니다.

**제약 조건:**

*   `1 <= nums.length <= 100`
*   `1 <= nums[i] <= 100`
*/
