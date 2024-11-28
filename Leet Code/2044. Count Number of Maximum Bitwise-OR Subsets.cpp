class Solution 
{
public:
    int countMaxOrSubsets(const vector<int>& nums)
    {
        generateSubsets(nums, 0, 0);
        return mCount;
    }

private:
    void generateSubsets(const vector<int>& nums, const int index, const int currentOR)
    {
        if (index == nums.size()) 
        {
            if (currentOR > mMaxORValue) 
            {
                mMaxORValue = currentOR;
                mCount = 1;
            } 
            else if (currentOR == mMaxORValue) 
            {
                ++mCount;
            }

            return;
        }

        generateSubsets(nums, index + 1, currentOR); // 현재 원소를 부분집합에 포함하지 않는 경우
        generateSubsets(nums, index + 1, currentOR | nums[index]); // 현재 원소를 부분집합에 포함하는 경우
    }

    int mMaxORValue = 0;  
    int mCount = 0;       
};


// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

/* 

---

**2044. 최대 비트 OR 부분집합의 개수 세기**  
난이도: 중간

주제: 비트 연산, 백트래킹, 조합

---

정수 배열 `nums`가 주어졌을 때, 배열 `nums`의 부분집합에서 가능한 최대 비트 OR 값을 찾고, 그 최대 비트 OR 값을 가지는 **서로 다른 비어 있지 않은 부분집합**의 개수를 반환하세요.

배열 `a`가 배열 `b`의 부분집합이라는 것은, `b`의 일부(혹은 전체)를 삭제하여 `a`를 얻을 수 있는 경우를 의미합니다. 선택된 요소의 인덱스가 다르면 두 부분집합은 서로 다른 것으로 간주됩니다.

배열 `a`의 비트 OR 값은 `a[0] | a[1] | ... | a[a.length - 1]` (0-인덱스 기준)과 같습니다.

---

### 예제 1:

입력:
```
nums = [3,1]
```
출력:
```
2
```
설명:
- 부분집합의 최대 비트 OR 값은 `3`입니다.
- 비트 OR 값이 `3`인 부분집합은 `[3]`, `[3, 1]` 두 개가 있습니다.

### 예제 2:

입력:
```
nums = [2,2,2]
```
출력:
```
7
```
설명:
- `[2, 2, 2]`의 모든 비어 있지 않은 부분집합의 비트 OR 값은 `2`입니다.
- 총 부분집합의 개수는 `2^3 - 1 = 7`입니다.

### 예제 3:

입력:
```
nums = [3,2,1,5]
```
출력:
```
6
```
설명:
- 부분집합의 최대 비트 OR 값은 `7`입니다.
- 비트 OR 값이 `7`인 부분집합은 `[3, 5]`, `[3, 1, 5]`, `[3, 2, 5]`, `[3, 2, 1, 5]`, `[2, 5]`, `[2, 1, 5]` 총 여섯 개가 있습니다.

---

### 제약 사항:

- `1 <= nums.length <= 16`
- `1 <= nums[i] <= 10^5`

이 문제는 주어진 배열의 부분집합 중 최대 비트 OR 값을 가지는 경우를 찾고, 그 경우의 수를 구하는 문제입니다. 부분집합을 구성하는 방법과 비트 연산을 통해 최대 OR 값을 찾는 것이 중요합니다.
*/
