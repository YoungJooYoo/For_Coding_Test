class Solution 
{
public:
    int countValidSelections(vector<int> nums) 
    {
        const size_t LENGTH = nums.size();
        int count = 0;

        // 각 0의 위치에서 시작하여 좌우 방향으로 유효성을 확인
        for (size_t i = 0; i < LENGTH; ++i)
        {
            if (nums[i] == 0)
            {
                if (canMakeAllZero(nums, i, DIRECTION_RIGHT) == true)  // 오른쪽으로 이동
                {
                    ++count;
                }
                if (canMakeAllZero(nums, i, DIRECTION_LEFT) == true) // 왼쪽으로 이동
                {
                    ++count;
                }
            }
        }

        return count;
    }

private:
    bool canMakeAllZero(vector<int> nums, size_t curr, bool direction)
    {
        const size_t LENGTH = nums.size();

        while (curr >= 0 && curr < LENGTH)
        {
            if (nums[curr] > 0)
            {
                --nums[curr]; // 현재 위치 값 감소
                direction = !direction; // 방향 전환
            }
            
            // 이동
            if (direction == DIRECTION_RIGHT)
            {
                ++curr;
            }
            else // direction == DIRECTION_LEFT
            {
                if (curr == 0)
                {
                    break; // 왼쪽 끝을 벗어나는 경우
                }
                --curr;
            }
        }

        // 모든 요소가 0인지 확인
        for (const auto& val : nums)
        {
            if (val != 0)
            {
                return false;
            }
        }

        return true;
    }

    enum
    {
        DIRECTION_LEFT = 0,
        DIRECTION_RIGHT = 1
    };
};

// https://leetcode.com/problems/make-array-elements-equal-to-zero/description/

/*


**3354. 배열의 모든 요소를 0으로 만들기**  
난이도: 쉬움

---

정수 배열 `nums`가 주어졌습니다.

처음에 `nums[curr] == 0`인 시작 위치 `curr`을 선택하고, 왼쪽 또는 오른쪽으로 이동할 방향을 선택합니다.

그 후, 다음 과정을 반복합니다:

1. 만약 `curr`이 범위 `[0, n - 1]`을 벗어나면 이 과정은 종료됩니다.
2. 만약 `nums[curr] == 0`이면, 현재 방향에 따라 `curr`을 증가(오른쪽 이동 시) 또는 감소(왼쪽 이동 시)시킵니다.
3. 그렇지 않고 `nums[curr] > 0`이면:
   - `nums[curr]`에서 1을 뺍니다.
   - 이동 방향을 반대로 바꿉니다 (왼쪽은 오른쪽으로, 오른쪽은 왼쪽으로).
   - 새로운 방향으로 한 걸음 이동합니다.

초기 위치 `curr`과 이동 방향을 선택했을 때, 모든 배열 요소가 0이 될 수 있다면 그 선택은 유효한 것으로 간주합니다.

유효한 초기 선택의 수를 반환하세요.

---

### 예제 1:

입력:
```
nums = [1,0,2,0,3]
```
출력:
```
2
```
설명:

유효한 선택은 다음과 같습니다:

- `curr = 3`을 선택하고 왼쪽으로 이동하는 경우:
  - `[1,0,2,0,3] -> [1,0,1,0,3] -> [1,0,1,0,2] -> [1,0,0,0,2] -> [1,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,0]`
- `curr = 3`을 선택하고 오른쪽으로 이동하는 경우:
  - `[1,0,2,0,3] -> [1,0,2,0,2] -> [1,0,1,0,2] -> [1,0,1,0,1] -> [1,0,0,0,1] -> [1,0,0,0,0] -> [0,0,0,0,0]`

### 예제 2:

입력:
```
nums = [2,3,4,0,4,1,0]
```
출력:
```
0
```
설명:

유효한 선택이 없습니다.

---

### 제약 사항:

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 100`
- `nums[i] == 0`인 요소가 적어도 하나 존재합니다.

이 문제는 배열 내에서 특정 위치를 시작으로 주어진 규칙에 따라 이동하여 모든 요소를 0으로 만들 수 있는지 확인하는 문제입니다. 유효한 시작 위치와 이동 방향의 개수를 계산하는 것이 목표입니다.
*/
