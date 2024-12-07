class Solution 
{
public:
    int minIncrementForUnique(vector<int>& nums) 
    {
        const size_t LENGTH = nums.size();
        int result = 0;

        sort(nums.begin(), nums.end());

        for (size_t i = 1; i < LENGTH; ++i)
        {
            if (nums[i - 1] >= nums[i])
            {
                result += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }

        return result;
    }
};

/*

### 945. 배열을 고유하게 만들기 위한 최소 증가 횟수

**난이도**: 중간  
**주제**: 배열 조작

---

#### 문제 설명

정수 배열 `nums`가 주어집니다.  
한 번의 이동에서, 배열 `nums`에서 `0 <= i < nums.length`를 만족하는 인덱스 `i`를 선택하여 `nums[i]` 값을 `1` 증가시킬 수 있습니다.

모든 값이 고유하도록 만들기 위해 필요한 최소 이동 횟수를 반환하세요.

테스트 케이스는 항상 답이 32비트 정수에 맞도록 생성됩니다.

---

#### 예제

**예제 1**:
```
입력: nums = [1,2,2]
출력: 1
설명: 1번 이동 후 배열은 [1, 2, 3]이 될 수 있습니다.
```

**예제 2**:
```
입력: nums = [3,2,1,2,1,7]
출력: 6
설명: 6번 이동 후 배열은 [3, 4, 1, 2, 5, 7]이 될 수 있습니다.
배열의 모든 값이 고유하도록 만드는 데 5번 이하의 이동으로는 불가능합니다.
```

---

#### 제약 사항

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^5`

--- 

#### 문제 풀이 목표

주어진 배열 `nums`를 고유한 값으로 만들기 위해 각 원소의 값을 `1`씩 증가시키는 최소 이동 횟수를 계산해야 합니다.
*/
