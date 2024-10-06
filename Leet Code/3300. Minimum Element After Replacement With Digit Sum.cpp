class Solution 
{
public:
    int minElement(vector<int>& nums) 
    {
        for (auto& num : nums)
        {
            int temp = 0;
            while (num != 0)
            {
                temp += (num % 10);
                num /= 10;
            }
            num = temp;
        }

        return *min_element(nums.begin(), nums.end());
    }
};

// https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/description/

/*

다음은 문제 3300의 한국어 번역입니다:

---

**3300. 자리수 합으로 교체한 후 최소 원소 구하기**

난이도: 쉬움

**문제 설명:**

정수 배열 `nums`가 주어집니다.

배열 `nums`의 각 원소를 그 자리수들의 합으로 교체합니다.

모든 교체가 끝난 후, `nums`에서 가장 작은 원소를 반환하세요.

---

**예시 1:**

- 입력: `nums = [10, 12, 13, 14]`
- 출력: `1`
- 설명: `nums`는 모든 교체가 끝난 후 `[1, 3, 4, 5]`가 되며, 그중 최소 원소는 1입니다.

**예시 2:**

- 입력: `nums = [1, 2, 3, 4]`
- 출력: `1`
- 설명: `nums`는 모든 교체가 끝난 후 `[1, 2, 3, 4]`가 되며, 그중 최소 원소는 1입니다.

**예시 3:**

- 입력: `nums = [999, 19, 199]`
- 출력: `10`
- 설명: `nums`는 모든 교체가 끝난 후 `[27, 10, 19]`가 되며, 그중 최소 원소는 10입니다.

---

**제약 조건:**

- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 10^4`

---

이 문제는 주어진 배열의 각 숫자를 자리수 합으로 변환한 후 가장 작은 값을 찾는 문제입니다.

*/
