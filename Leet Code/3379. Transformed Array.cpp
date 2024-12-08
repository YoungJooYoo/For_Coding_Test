class Solution 
{
public:
    vector<int> constructTransformedArray(const vector<int>& nums) 
    {
        const int LENGTH = nums.size();
        vector<int> result(LENGTH, 0);

        for (int i = 0; i < LENGTH; ++i)
        {
            if (nums[i] == 0)
            {
                result[i] = nums[i];
            }
            else if (nums[i] > 0)
            {
                const int IDX = (i + nums[i]) % LENGTH;
                result[i] = nums[IDX];
            }
            else if (nums[i] < 0)
            {
                const int IDX = (i + (nums[i] % LENGTH) + LENGTH) % LENGTH;
                result[i] = nums[IDX];
            }
        }

        return result;
    }
};


// https://leetcode.com/problems/transformed-array/description/

/*
### 문제 설명

정수 배열 `nums`가 원형 배열로 주어집니다. 다음 규칙에 따라 같은 크기의 새로운 배열 `result`를 생성하는 것이 목표입니다:

1. 각 인덱스 `i`(0 ≤ i < nums.length)에 대해 독립적으로 다음 작업을 수행합니다:
   - 만약 `nums[i] > 0`이면: 
     - 인덱스 `i`에서 시작하여 원형 배열에서 오른쪽으로 `nums[i]`만큼 이동합니다. 
     - 도착한 인덱스의 값을 `result[i]`에 설정합니다.
   - 만약 `nums[i] < 0`이면:
     - 인덱스 `i`에서 시작하여 원형 배열에서 왼쪽으로 `abs(nums[i])`만큼 이동합니다.
     - 도착한 인덱스의 값을 `result[i]`에 설정합니다.
   - 만약 `nums[i] == 0`이면:
     - `result[i]`에 `nums[i]` 값을 설정합니다.

2. **원형 배열**이기 때문에 마지막 원소를 넘어가면 배열의 시작으로 돌아가고, 첫 번째 원소를 벗어나면 배열의 끝으로 돌아갑니다.

---

### 예제

**예제 1**:
```
입력: nums = [3, -2, 1, 1]
출력: [1, 1, 1, 3]

설명:
- nums[0] = 3: 오른쪽으로 3칸 이동하면 nums[3]에 도착. result[0] = 1
- nums[1] = -2: 왼쪽으로 2칸 이동하면 nums[3]에 도착. result[1] = 1
- nums[2] = 1: 오른쪽으로 1칸 이동하면 nums[3]에 도착. result[2] = 1
- nums[3] = 1: 오른쪽으로 1칸 이동하면 nums[0]에 도착. result[3] = 3
```

**예제 2**:
```
입력: nums = [-1, 4, -1]
출력: [-1, -1, 4]

설명:
- nums[0] = -1: 왼쪽으로 1칸 이동하면 nums[2]에 도착. result[0] = -1
- nums[1] = 4: 오른쪽으로 4칸 이동하면 nums[2]에 도착. result[1] = -1
- nums[2] = -1: 왼쪽으로 1칸 이동하면 nums[1]에 도착. result[2] = 4
```

---

### 제약 조건

- `1 ≤ nums.length ≤ 100`
- `-100 ≤ nums[i] ≤ 100` 

--- 

### 목표

위의 규칙을 사용하여 `result` 배열을 생성하고 반환하는 함수를 작성하세요.

*/
