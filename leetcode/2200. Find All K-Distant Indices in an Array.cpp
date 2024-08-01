class Solution 
{
public:
    vector<int> findKDistantIndices(const vector<int>& nums, const int key, const int k) 
    {
        const size_t LENGTH = nums.size();
        vector<int> index;
        vector<int> result;

        // key랑 일치하는 idx 찾기
        for (size_t i = 0; i < LENGTH; ++i)
        {
            if (nums[i] == key)
            {
                index.push_back(i);
            }
        }

        for (int i = 0; i < LENGTH; ++i)
        {
            for (int j = 0; j < index.size(); ++j)
            {
                const int distance = abs(i - index[j]);
                if (distance <= k  && find(result.begin(), result.end(), i) == result.end())
                {
                    result.push_back(i);
                }
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/description/

/*

### 2200. 배열에서 모든 K-거리 인덱스를 찾기

**난이도: 쉬움**

#### 문제 설명

0-인덱스 정수 배열 `nums`와 두 정수 `key` 및 `k`가 주어집니다. `k`-거리 인덱스는 `nums`의 인덱스 `i`로, 적어도 하나의 인덱스 `j`가 다음 조건을 만족하는 경우를 의미합니다:

- |i - j| <= k
- nums[j] == key

이러한 모든 `k`-거리 인덱스를 오름차순으로 정렬된 리스트로 반환하세요.

#### 예제

**예제 1**:

- **입력**: `nums = [3,4,9,1,3,9,5]`, `key = 9`, `k = 1`
- **출력**: `[1,2,3,4,5,6]`
- **설명**: 
  - 여기서 `nums[2] == key`이고 `nums[5] == key`입니다.
  - 인덱스 0의 경우, |0 - 2| > k 및 |0 - 5| > k이므로, `|0 - j| <= k`이고 `nums[j] == key`인 `j`가 없습니다. 따라서 0은 k-거리 인덱스가 아닙니다.
  - 인덱스 1의 경우, |1 - 2| <= k이고 `nums[2] == key`이므로 1은 k-거리 인덱스입니다.
  - 인덱스 2의 경우, |2 - 2| <= k이고 `nums[2] == key`이므로 2는 k-거리 인덱스입니다.
  - 인덱스 3의 경우, |3 - 2| <= k이고 `nums[2] == key`이므로 3은 k-거리 인덱스입니다.
  - 인덱스 4의 경우, |4 - 5| <= k이고 `nums[5] == key`이므로 4는 k-거리 인덱스입니다.
  - 인덱스 5의 경우, |5 - 5| <= k이고 `nums[5] == key`이므로 5는 k-거리 인덱스입니다.
  - 인덱스 6의 경우, |6 - 5| <= k이고 `nums[5] == key`이므로 6은 k-거리 인덱스입니다.
  - 따라서 우리는 [1,2,3,4,5,6]을 반환하며 이는 오름차순으로 정렬되어 있습니다.

**예제 2**:

- **입력**: `nums = [2,2,2,2,2]`, `key = 2`, `k = 2`
- **출력**: `[0,1,2,3,4]`
- **설명**: 
  - `nums`의 모든 인덱스 `i`에 대해, `|i - j| <= k`이고 `nums[j] == key`인 `j`가 존재합니다. 따라서 모든 인덱스가 k-거리 인덱스입니다.
  - 그래서 우리는 [0,1,2,3,4]를 반환합니다.

#### 제약 조건

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 1000`
- `key`는 배열 `nums`의 정수 중 하나입니다.
- `1 <= k <= nums.length`

*/
