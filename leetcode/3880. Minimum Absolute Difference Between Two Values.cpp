class Solution
{
public:
    int minAbsoluteDifference(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= static_cast<int>(nums.size()) && static_cast<int>(nums.size()) <= MAX_LENGTH);

        const size_t LENGTH = nums.size();
        vector<int> oneIndices;
        vector<int> twoIndices;

        for (size_t i = 0; i < LENGTH; ++i)
        {
            assert(MIN_VALUE <= nums[i] && nums[i] <= MAX_VALUE);
            if (nums[i] == 1)
            {
                oneIndices.push_back(static_cast<int>(i));
            }
            else if (nums[i] == 2)
            {
                twoIndices.push_back(static_cast<int>(i));
            }
        }

        if (oneIndices.empty() == true || twoIndices.empty() == true) // 1 또는 2가 없으면 유효한 쌍 없음
        {
            return FAIL;
        }

        int minAbsDiff = numeric_limits<int>::max(); // 모든 (1의 index, 2의 index) 쌍에서 절댓값 최솟값 탐색
        for (const int oneIndex : oneIndices)
        {
            for (const int twoIndex : twoIndices)
            {
                const int absDiff = abs(oneIndex - twoIndex);
                minAbsDiff = min(minAbsDiff, absDiff);
            }
        }

        return minAbsDiff;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_VALUE  = 0,
        MAX_VALUE  = 2,
        FAIL       = -1,
    };
};

/*

https://leetcode.com/problems/minimum-absolute-difference-between-two-values/description/

**3880. 두 값 사이의 최소 절대 차이**

0, 1, 2로만 이루어진 정수 배열 `nums`가 주어집니다.

인덱스 쌍 `(i, j)`는 `nums[i] == 1` 이고 `nums[j] == 2` 일 때 **유효한 쌍**이라고 합니다.

모든 유효한 쌍 중에서 `i`와 `j`의 **최소 절대 차이**를 반환하세요. 유효한 쌍이 없으면 `-1`을 반환하세요.

인덱스 `i`와 `j`의 절대 차이는 `abs(i - j)`로 정의합니다.

---

**예시 1**
- 입력: `nums = [1,0,0,2,0,1]`
- 출력: `2`
- 설명:
  - 유효한 쌍: `(0, 3)` → `abs(0-3) = 3`
  - 유효한 쌍: `(5, 3)` → `abs(5-3) = 2`
  - 최솟값 → `2`

**예시 2**
- 입력: `nums = [1,0,1,0]`
- 출력: `-1`
- 설명: 배열에 2가 없으므로 유효한 쌍이 존재하지 않음 → `-1`

---

**제약 조건**
- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 2`

---

## 요약

값이 `1`인 인덱스와 값이 `2`인 인덱스 사이의 **인덱스 거리가 가장 짧은 쌍**을 찾아 반환. 없으면 `-1`.

---

## 풀이 방향

1. `1`의 인덱스들과 `2`의 인덱스들을 각각 별도로 수집
2. 둘 중 하나라도 비어있으면 → `-1` 반환
3. 모든 `(i, j)` 쌍에 대해 `abs(i - j)` 계산 후 최솟값 반환


*/
