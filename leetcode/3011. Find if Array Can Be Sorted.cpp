class Solution 
{
public:
    bool canSortArray(const vector<int>& nums) 
    {
        vector<int> copy_nums(nums.begin(), nums.end());
        const size_t LENGTH = copy_nums.size();
        size_t index = 0;

        while (index < LENGTH - 1) 
        {
            const int setBitsCurrent = __builtin_popcount(copy_nums[index]);
            const int setBitsNext = __builtin_popcount(copy_nums[index + 1]);

            if (copy_nums[index] > copy_nums[index + 1] && setBitsCurrent == setBitsNext) 
            {
                swap(copy_nums[index], copy_nums[index + 1]);
                index = 0; // 다시 처음부터 확인
            } 
            else if (copy_nums[index] <= copy_nums[index + 1]) 
            {
                ++index; // 다음 요소로 이동
            } 
            else if (copy_nums[index] > copy_nums[index + 1] && setBitsCurrent != setBitsNext) 
            {
                return false; // 비트 수가 다르고 정렬이 불가능한 경우
            }
        }

        // 마지막으로 전체 배열이 정렬되었는지 확인
        for (size_t i = 1; i < LENGTH; ++i) 
        {
            if (copy_nums[i - 1] > copy_nums[i])
            {
                return false;
            }
        }

        return true;
    }
};

// https://leetcode.com/problems/find-if-array-can-be-sorted/description/?envType=daily-question&envId=2024-11-06

/*

---

**3011. 배열을 정렬할 수 있는지 찾기**  
난이도: 중간

---

양의 정수로 이루어진 0부터 시작하는 인덱스의 배열 `nums`가 주어집니다.

한 번의 연산으로, **같은 수의 1 비트(set bits)**를 가진 인접한 두 요소를 서로 교환할 수 있습니다. 이 연산은 원하는 만큼 (0번 포함) 수행할 수 있습니다.

배열을 정렬할 수 있다면 `true`를 반환하고, 그렇지 않으면 `false`를 반환하세요.

---

### 예제 1:

입력: 
```
nums = [8,4,2,30,15]
```
출력: 
```
true
```
설명:
- 각 요소의 이진 표현을 봅시다. 숫자 `2`, `4`, `8`은 각각 이진 표현이 `"10"`, `"100"`, `"1000"`이며, 모두 1개의 1 비트를 가집니다. 숫자 `15`와 `30`은 이진 표현이 각각 `"1111"`과 `"11110"`로, 4개의 1 비트를 가집니다.
- 우리는 4번의 연산을 통해 배열을 정렬할 수 있습니다:
  - `nums[0]`과 `nums[1]`을 교환합니다. 이 연산은 `8`과 `4`가 각각 1개의 1 비트를 가지고 있기 때문에 유효합니다. 배열은 `[4,8,2,30,15]`이 됩니다.
  - `nums[1]`과 `nums[2]`를 교환합니다. 이 연산은 `8`과 `2`가 각각 1개의 1 비트를 가지고 있기 때문에 유효합니다. 배열은 `[4,2,8,30,15]`이 됩니다.
  - `nums[0]`과 `nums[1]`을 교환합니다. 이 연산은 `4`와 `2`가 각각 1개의 1 비트를 가지고 있기 때문에 유효합니다. 배열은 `[2,4,8,30,15]`이 됩니다.
  - `nums[3]`과 `nums[4]`를 교환합니다. 이 연산은 `30`과 `15`가 각각 4개의 1 비트를 가지고 있기 때문에 유효합니다. 배열은 `[2,4,8,15,30]`이 됩니다.
- 배열이 정렬되었으므로 `true`를 반환합니다.
- 다른 연산 순서로도 배열을 정렬할 수 있습니다.

### 예제 2:

입력: 
```
nums = [1,2,3,4,5]
```
출력: 
```
true
```
설명:
- 배열은 이미 정렬되어 있으므로 `true`를 반환합니다.

### 예제 3:

입력: 
```
nums = [3,16,8,4,2]
```
출력: 
```
false
```
설명:
- 주어진 배열을 어떠한 연산을 통해서도 정렬할 수 없음을 보일 수 있습니다.

---

### 제약 사항:

- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 28` 

이 문제는 배열의 요소들을 교환하여 정렬할 수 있는지 여부를 확인하는 문제로, 요소들 간의 이진 표현에서 1 비트의 개수를 활용합니다.
*/
