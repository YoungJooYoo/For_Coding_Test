class Solution 
{
public:
    vector<int> orArray(const vector<int>& nums) 
    {
        vector<int> result;
        const size_t LENGTH = nums.size();

        for (size_t i = 0; i < LENGTH - 1; ++i)
        {
            const int temp = nums[i + 1] | nums[i];
            result.push_back(temp);
        }

        return result;
    }
};

/*
### 3173. 인접한 요소들의 비트 OR

#### 난이도: 쉬움

#### 힌트
주어진 길이 n의 배열 `nums`가 있을 때, 길이 n - 1의 배열 `answer`를 반환하세요. 
여기서 `answer[i] = nums[i] | nums[i + 1]`입니다. 여기서 `|`는 비트 OR 연산입니다.

#### 예제 1:
- 입력: `nums = [1, 3, 7, 15]`
- 출력: `[3, 7, 15]`

#### 예제 2:
- 입력: `nums = [8, 4, 2]`
- 출력: `[12, 6]`

#### 예제 3:
- 입력: `nums = [5, 4, 9, 11]`
- 출력: `[5, 13, 11]`

#### 제약 사항:
- `2 <= nums.length <= 100`
- `0 <= nums[i] <= 100`
*/

// https://leetcode.com/problems/bitwise-or-of-adjacent-elements/
