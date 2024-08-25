class Solution 
{
public:
    vector<int> getFinalState(vector<int>& nums, int k, const int multiplier) 
    {
        for (size_t i = 0; i < k; ++i)
        {
            const int min_index = min_element(nums.begin(), nums.end()) - nums.begin();
            nums[min_index] *= multiplier;
        }

        return nums;
    }
};

// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/

/*

### 문제 번역:

당신에게 정수 배열 `nums`, 정수 `k`, 그리고 정수 `multiplier`가 주어집니다.

당신은 `nums`에 대해 `k`번의 연산을 수행해야 합니다. 각 연산에서 다음을 수행합니다:

1. `nums`에서 최솟값 `x`를 찾습니다. 만약 최솟값이 여러 번 등장한다면, 첫 번째로 등장하는 것을 선택합니다.
2. 선택한 최솟값 `x`를 `x * multiplier`로 대체합니다.

`k`번의 연산을 모두 수행한 후 `nums`의 최종 상태를 나타내는 정수 배열을 반환하세요.

### 예제:

**예제 1:**

- 입력: `nums = [2,1,3,5,6]`, `k = 5`, `multiplier = 2`
- 출력: `[8,4,6,5,6]`

**설명:**

| 연산 후 | 결과                       |
|----------|----------------------------|
| 연산 1   | `[2, 2, 3, 5, 6]`          |
| 연산 2   | `[4, 2, 3, 5, 6]`          |
| 연산 3   | `[4, 4, 3, 5, 6]`          |
| 연산 4   | `[4, 4, 6, 5, 6]`          |
| 연산 5   | `[8, 4, 6, 5, 6]`          |

**예제 2:**

- 입력: `nums = [1,2]`, `k = 3`, `multiplier = 4`
- 출력: `[16,8]`

**설명:**

| 연산 후 | 결과          |
|----------|---------------|
| 연산 1   | `[4, 2]`      |
| 연산 2   | `[4, 8]`      |
| 연산 3   | `[16, 8]`     |

### 제약 조건:

- `nums.length`는 `1` 이상 `100` 이하입니다.
- `nums[i]`는 `1` 이상 `100` 이하입니다.
- `k`는 `1` 이상 `10` 이하입니다.
- `multiplier`는 `1` 이상 `5` 이하입니다.

*/
