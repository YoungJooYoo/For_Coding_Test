class Solution 
{
public:
    long long countFairPairs(vector<int>& nums, const int lower, const int upper) 
    {
        const size_t LENGTH = nums.size();
        long long pairsCount = 0;

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < LENGTH; ++i)
        {
            const auto startIterator = nums.begin() + i + 1; // 이분 탐색의 시작 지점을 변수로 저장
            const int targetLower = lower - nums[i]; // nums[i]와의 합이 lower 이상인 최소 인덱스 찾기
            const int leftBoundIndex = lower_bound(startIterator, nums.end(), targetLower) - nums.begin();
            const int targetUpper = upper - nums[i]; // nums[i]와의 합이 upper 이하인 최대 인덱스 찾기
            const int rightBoundIndex = upper_bound(startIterator, nums.end(), targetUpper) - nums.begin() - 1;
            const int possiblePairsCount = rightBoundIndex - leftBoundIndex + 1; // 가능한 쌍의 개수를 계산하기 위한 변수 정의

            if (leftBoundIndex <= rightBoundIndex)
            {
                pairsCount += possiblePairsCount;
            }
        }

        return pairsCount;
    }
};


// https://leetcode.com/problems/count-the-number-of-fair-pairs/description/?submissionId=1452641237


/*

---

**2563. 공정한 쌍의 개수 세기**  
난이도: 중간

---

0부터 시작하는 인덱스를 가진 크기 `n`의 정수 배열 `nums`와 두 정수 `lower`와 `upper`가 주어질 때, 
**공정한 쌍의 개수**를 반환하세요.

쌍 `(i, j)`가 공정하다고 하려면 다음 조건을 만족해야 합니다:

1. `0 <= i < j < n`
2. `lower <= nums[i] + nums[j] <= upper`

---

### 예제 1:

입력: 
```
nums = [0, 1, 7, 4, 4, 5], lower = 3, upper = 6
```
출력: 
```
6
```
설명:
- 공정한 쌍은 총 6개입니다: `(0,3)`, `(0,4)`, `(0,5)`, `(1,3)`, `(1,4)`, `(1,5)`.

### 예제 2:

입력: 
```
nums = [1, 7, 9, 2, 5], lower = 11, upper = 11
```
출력: 
```
1
```
설명:
- 공정한 쌍은 단 하나입니다: `(2,3)`.

---

### 제약 사항:

- `1 <= nums.length <= 10^5`
- `nums.length == n`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= lower <= upper <= 10^9`

이 문제는 배열 `nums`에서 두 요소의 합이 `lower`와 `upper` 사이에 포함되는 쌍 `(i, j)`의 개수를 찾는 문제입니다. 각 쌍 `(i, j)`에서 `i`는 `j`보다 작아야 합니다. 효율적인 탐색 알고리즘을 사용하여 가능한 쌍을 찾아야 합니다.

*/
