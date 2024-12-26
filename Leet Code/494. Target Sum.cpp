class Solution 
{
public:
    Solution()
    : mCount(0)
    {

    }

    int findTargetSumWays(const vector<int>& nums, const int target) 
    {
        findTargetSumWaysHelper(nums, target, 0, -nums[0]);
        findTargetSumWaysHelper(nums, target, 0, +nums[0]);
        return mCount;
    }

private:
    void findTargetSumWaysHelper(const vector<int>& nums, const int target, const size_t currentIndex, const int sum)
    {
        if (currentIndex + 1 >= nums.size())
        {
            if (sum == target)
            {
                ++mCount;
            }

            return;
        } 

        findTargetSumWaysHelper(nums, target, currentIndex + 1, sum - nums[currentIndex + 1]);
        findTargetSumWaysHelper(nums, target, currentIndex + 1, sum + nums[currentIndex + 1]);
    }

    int mCount;
};

// https://leetcode.com/problems/target-sum/description/?envType=daily-question&envId=2024-12-26

/*
### 문제: 목표 합(Target Sum)

#### 문제 설명

정수 배열 `nums`와 정수 `target`이 주어집니다.

`nums`의 각 정수 앞에 `+` 또는 `-` 기호를 추가하여 식(expression)을 만듭니다. 그리고 이렇게 만든 식이 `target`과 같은 값을 갖도록 하고 싶습니다.

예를 들어:
- `nums = [2, 1]`의 경우:
  - `+2-1` 또는 `-2+1`와 같은 식을 생성할 수 있습니다.

`target` 값을 만들 수 있는 서로 다른 식(expression)의 개수를 반환하세요.

---

#### 입력 및 출력 예시

**예제 1:**

```plaintext
입력: nums = [1,1,1,1,1], target = 3
출력: 5
```

**설명:**
`nums` 배열에 기호를 할당하여 `target = 3`을 만족하는 경우는 다음 5가지입니다:
- `-1 + 1 + 1 + 1 + 1 = 3`
- `+1 - 1 + 1 + 1 + 1 = 3`
- `+1 + 1 - 1 + 1 + 1 = 3`
- `+1 + 1 + 1 - 1 + 1 = 3`
- `+1 + 1 + 1 + 1 - 1 = 3`

---

**예제 2:**

```plaintext
입력: nums = [1], target = 1
출력: 1
```

**설명:**
- `+1` 한 가지 방법만 가능합니다.

---

#### 제약 사항

- `1 <= nums.length <= 20`
- `0 <= nums[i] <= 1000`
- `0 <= sum(nums[i]) <= 1000`
- `-1000 <= target <= 1000`
*/
