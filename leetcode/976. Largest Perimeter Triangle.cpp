class Solution {
public:
    int largestPerimeter(vector<int>& nums) 
    {
        const  size_t LENGTH = nums.size();
        int result = 0;

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < LENGTH - 2; ++i)
        {
            if (nums[i] + nums[i + 1] > nums[i + 2])
            {
                result = max(result, nums[i] + nums[i + 1] + nums[i + 2]);
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/largest-perimeter-triangle/description/

/*
### 976. 가장 큰 둘레의 삼각형

**난이도: 쉬움**

#### 문제 설명

정수 배열 `nums`가 주어집니다. 이 배열에서 세 길이를 선택하여 넓이가 0이 아닌 삼각형을 만들 수 있는 가장 큰 둘레를 반환하세요. 넓이가 0인 삼각형을 만들 수 없는 경우 0을 반환하세요.

#### 예제

**예제 1**:

- **입력**: `nums = [2,1,2]`
- **출력**: `5`
- **설명**: 길이가 1, 2, 2인 삼각형을 만들 수 있습니다.

**예제 2**:

- **입력**: `nums = [1,2,1,10]`
- **출력**: `0`
- **설명**: 다음 조합으로는 삼각형을 만들 수 없습니다:
  - 1, 1, 2
  - 1, 1, 10
  - 1, 2, 10
  따라서 넓이가 0인 삼각형을 만들 수 없으므로 0을 반환합니다.

#### 제약 조건

- `3 <= nums.length <= 10^4`
- `1 <= nums[i] <= 10^6`

*/
