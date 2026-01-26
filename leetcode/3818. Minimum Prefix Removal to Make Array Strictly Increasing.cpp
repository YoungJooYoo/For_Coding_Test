class Solution
{
public:
    int minimumPrefixLength(vector<int>& nums) const
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);
        const size_t LENGTH = nums.size();
        int increasingLength = 1;
        
        for (int i = LENGTH - 1; i > 0; --i)
        {
            assert(MIN_NUM <= nums[i] && nums[i] <= MAX_NUM);
            if(nums[i] > nums[i - 1])
            {
                ++increasingLength;
            }
            else
            {
                return LENGTH - increasingLength;
            }
        }

        assert(increasingLength >= 0 && LENGTH - increasingLength >= 0);
        return LENGTH - increasingLength;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000,
        MIN_NUM = -1000000000,
        MAX_NUM = 1000000000
    };
};


/*
https://leetcode.com/problems/minimum-prefix-removal-to-make-array-strictly-increasing/

### 3818. 배열을 엄격하게 증가하게 만들기 위한 최소 접두사 제거

**문제 설명**
정수 배열 `nums`가 주어집니다.

`nums`에서 **정확히 하나의 접두사**(비어 있을 수 있음)를 제거해야 합니다.

남은 배열이 **엄격하게 증가(strictly increasing)**하는 상태가 되도록 하는 제거된 접두사의 **최소 길이**를 정수로 반환하세요.

**예시 1:**
*   **입력:** `nums = [1, -1, 2, 3, 3, 4, 5]`
*   **출력:** `4`
*   **설명:** 접두사 `[1, -1, 2, 3]`을 제거하면 남은 배열은 `[3, 4, 5]`가 되며, 이는 엄격하게 증가하는 상태입니다.

**예시 2:**
*   **입력:** `nums = [4, 3, -2, -5]`
*   **출력:** `3`
*   **설명:** 접두사 `[4, 3, -2]`를 제거하면 남은 배열은 `[-5]`가 되며, 이는 엄격하게 증가하는 상태입니다.

**예시 3:**
*   **입력:** `nums = [1, 2, 3, 4]`
*   **출력:** `0`
*   **설명:** 배열 `nums = [1, 2, 3, 4]`는 이미 엄격하게 증가하는 상태이므로 빈 접두사를 제거하는 것으로 충분합니다.

**제약 사항:**
*   `1 <= nums.length <= 10^5`
*   `-10^9 <= nums[i] <= 10^9`

---

**힌트:**
남은 배열이 "엄격하게 증가"해야 하므로, 배열의 **뒤에서부터** 요소들을 확인하며 어디까지 증가 상태가 유지되는지 찾아보시는 것을 추천합니다. 어느 지점에서 증가 상태가 깨지는지 확인해 보시겠어요?
*/
